---
layout: post
title:  "Metal Claw"
date:   2014-10-04
categories: devlog
---

Like any piece of software that wants to preserve some state data for the next time it runs, wombat needs to store and retrieve certain data it cares about accessing later. For wombat, this includes things like game saves, creature definitions, world layout, and a good deal more. Software uses a variety of formats to store this type of data in, and wombat does this by representing data structures in files, using a format called JSON. Representing this data in JSON allows for easy debugging, as it is a human readable data serialization format, however that convenience is not without a performance and storage cost. On modern PCs, this cost is negligable, but even a surface level feasability study for the GBA port makes it perfectly clear that this cost is far too high for such a limited piece of hardware. To illustrate this problem, wombat will need to store a modified copy of the area that the user occupies when it saves the game. Currently, such an area would use around 33 KB for a 25x25 tile area that is more or less empty and has unneeded data stripped out. GBA cartridges typically offer around 64 KB for such data, so, something obviously has to give.

To address this issue, a more efficient serialization format is needed, hence Metal Claw. Metal Claw is a more compact alternative to JSON planned for use in the GBA version of wombat.

### Requirements and Assumptions
In designing Metal Claw, we will assume that values have no null or undefined state, but they do have default values that they receive if the serialized representation provides none.

Default values:

* String: ""
* Integer and floats: 0
* Bool: false
* Arrays and maps: empty

We will also assume the trustworthiness of any given Metal Claw file with regards to exploits related to buffer overflows. While the implementation will guard against such things, the depth of vetting will make no promises regarding such security.

Take the following model as an example:
{% highlight go %}
Model
	Field1 int
	Field2 string
	Field3 bool
	Field4 bool
	Field5 bool
	Field6 bool
	Field7 bool
	Field8 bool
{% endhighlight %}


Not counting the unnecessary whitespace, the following JSON text is 47 bytes.
{% highlight go %}
{"Field1": 25, "Field2": "A string", "Field3": true}
{% endhighlight %}

Let's see how much we can reduce the size of our example here, as we transform it from JSON to Metal Claw.

### Eliminate Field Names
One of the biggest sources of bloat inherit to JSON is found in the variable labels in objects. Field names make for a readable and robust format, but more efficient ways of differentiating fields in a serialization format exist. Another method, is defining a set order in which each field will appear in the serialized representation of the data. Eliminating the field names alone will often inflate the size of the data, but this is an important stepping stone in reducing the size of the data.

Here are some examples that showcase the strengths and weaknesses of this approach.

In this case previously undefined fields must also be defined, which inflates the size of the data to 50 bytes.
{% highlight go %}
{25, "A string", true, false, false, false, false, false}
{% endhighlight %}

While this inflates our primary sample data, the following case shows that it can reduce the size.
{% highlight go %}
{"Field1": 25, "Field2": "A string", "Field3": true, "Field8": true}
{25, "A string", true, false, false, false, false, true}
{% endhighlight %}

As demonstrated above, the usefulness of field name elimination in isolation is spotty. While eliminating field names can help in some cases, more often it inflates the size of the data, so a replacement for this functionality is highly desired.

### Field Presence Masks
To combat the bloat that often comes with the absence of the field names, we can use field presence masks.

With a field presence mask, we can eliminate the default values listed here. The mask to describe our example data would be the following in binary, 11100000, or 225 in decimal. With the addition of the field presence mask, the data now now only needs 25 bytes.
{% highlight go %}
{225, 25, "A string", true}
{% endhighlight %}

The presence mask actually provides further size reduction with bools. Bools only have 2 possible values, just as each bit in the presence mask, and so the presence bit can actually contain the data of the bool, thus making the bool redundant. With this in mind, our example data is now reduced to 19 bytes.
{% highlight go %}
{225, 25, "A string"}
{% endhighlight %}

### Variable Length Binary Integers
As it stands, the current representation of integers can prove quite wasteful. The number 25 should take only 1 byte to represent, but it uses 2 bytes in the current representation. To address this, it is helpfull just represent the integer in binary instead of plain text. Unfortunately, this can actually prove even more wasteful. cyborgbear assumes all integers are 32 bit when they are defined, which means that the 2 byte plain text representation of 25 inflates to 4 bytes. This works out well for numbers greater than 9,999, but if a large portion of the numbers represented fall below 1,000, then it will generaly cost more space than it saves.

For a solid compromise, we'll take a page from the design of Unicode, and allow continuation bytes. Integers within the -64 to 63 range will be 8 bits, outside that range they will move on to 16, 24, or 32 bits as needed.

Starting with the most significant bit, we start looking for the first 0 in the first byte in the integer, and for every 1 found before that, there will be one additional continuation byte. 00011001 has no continuation bytes, whereas 10011001 has 1 continuation byte, and so on.

From here on out, we will use the use the following notation to denote an variable length integer stored in binary, (25). <25> will represent a fixed length binary integer.

Using variable length integers, we can reduce our current example data to 16 bytes.

{% highlight go %}
{<225>, (25), "A string"}
{% endhighlight %}

### Eliminate Delimiter Characters
Like field names, delimiter characters make for a robust data format, and provide specific format information for the data with the data itself. Also like field names, the delimiter characters are unnecessary if we already know the format of the data, and so we can get rid of them.

With this change, our example data has been reduced to 12 bytes.

{% highlight go %}
<225>(25)"A string"
{% endhighlight %}

A further change that will allow for much faster string parsing is to replace string beginning and ending delimiters with the length of the string. In many cases this will reduce the size of the string by 1 byte, but it can end up bigger. In the case of our sample data, this reduces it to 11 bytes.

{% highlight go %}
<225>(25)(8)A string
{% endhighlight %}

### Conclusion
Here's what the actual end result of the our data's transition from JSON to Metal Claw will look like if opened in Vim:
```
á^Y^HA string
```

This makes for a good start, but as it stands Metal Claw still lacks some critical features. In part 2 we will expand Metal Claw to support lists and maps.
