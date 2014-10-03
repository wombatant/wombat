---
layout: post
title:  "Data Models"
date:   2014-10-03
categories: devlog
---

Like any piece of software that wants to preserve some state data for the next time it runs, wombat needs to be able to store and retrieve certain data it cares about accessing later. For wombat, this includes things like game saves, creature definitions, world layout, and a good deal more. Software uses a variety of formats to store this type of data in, and wombat does this by representing data structures in files, using a format called JSON. Representing this data in JSON allows for easy debugging, as it is a human readable data serialization format, however that convenience is not without a small performance and storage cost. On modern PCs, this cost is negligable, but even a surface level feasability study for the GBA port makes it perfectly clear that this cost is far too high for such a limited piece of hardware. To illustrate this problem, wombat will need to store a modified copy of the area that the user occupies when it saves the game. Currently, such an area would use around 33 KB for a 25x25 tile area that is more or less empty and has unneeded data stripped out. GBA cartridges typically offer around 64 KB for such data, so, something obviously has to give.

To address this issue, a more efficient serialization format called Metal Claw is planned as an alternative for the GBA version of wombat.
