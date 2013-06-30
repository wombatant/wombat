Animation
	Interval	int
	Images		[]Image

AnimLayer
	Point		Point
	Animation	Animation

CreatureType
	Name			map[string]string
	Special			bool
	StrongAgainst	[]string
	WeakAgainst		[]string

CreatureClass
	Name			map[string]string
	Successor		string
	Predecessor		string
	Types			[]string
	CanLearn		[]string
	LearnsAtLevel	map[int]string
	FrontView		Animation
	BackView		Animation

CreatureMove
	Name			map[string]string
	Type			string
	Power			int
	RequiresRegarge	bool
	Script			string
	Burn			StatusEffect
	Freeze			StatusEffect
	Paralyze		StatusEffect
	Poison			StatusEffect
	Sleep			StatusEffect

CreatureMoveInstance
	CreatureMove	int
	PP				Fraction

Creature
	ID				int
	Name			map[string]string
	CreatureClass	string
	Male			bool
	Level			int
	Health			Fraction
	Attack			int
	SpecAttack		int
	Defense			int
	SpecDefense		int
	Burned			bool
	Frozen			bool
	Poisoned		bool
	Asleep			bool
	Moves			[]CreatureMoveInstance

StatusEffect
	AttackerEffect	int
	EnemyEffect		int

Fraction
	Current		int
	Available	int

Image
	Size	Size
	Path	string

ModelFile
	Type	string

PersonClass
	ID			int
	Name		map[string]string
	Creatures	[]int
	Overhead	[]Animation
	FrontView	Animation
	BackView	Animation

Person
	PersonClass	PersonClass

Point
	X int
	Y int

Size
	Width	int
	Height	int

Sprite
	AnimLayers	[][]AnimLayer
	SpriteType	int
	PersonID	int
	Speed		int
	Name		string
	Path		string
	ScriptPath	string

TileClass
	TerrainFlags	int
	Import			string
	LowerAnims		[]AnimLayer
	UpperAnims		[]AnimLayer

Tile
	TileClass	TileClass
	Occupant	Sprite

World
	Zones	[]ZoneInstance

Zone
	Tiles		[][][]Tile
	InitScripts	[]string
	Location	Point

ZoneHeader
	Path	string
	Size	Size

ZoneInstance
	AccessorID	string
	Path		string
	Location	Point

User
	PersonID	int
	World		string
	Zone		string
	XAddress	int
	YAddress	int
	Layer		int

SaveFile
	Vars map[string]unknown
	User User
