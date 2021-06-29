# Vectors

## Vector2
### Constructors
Return Type | Method | Parameters | Description
------------ | ------------- | ------------- | -------------
 | Vector2 |  | Constructs a Vector with (0, 0) float values.
 | Vector2 | Vector2 | Constructs a Vector from another vector of the same type.
 | Vector2 | float x, float y | Constructs a Vector with two float values.

### Destructor
Return Type | Method | Parameters | Description
------------ | ------------- | ------------- | -------------
 | ~Vector2 |  | 

### Public Methods
Return Type | Method | Parameters | Description
------------ | ------------- | ------------- | -------------
void | Normalize |  | Makes this vector have a magnitude of 1.
string | ToString |  | Returns a formatted string for this vector.

### Static Methods
float | Angle | Vector2 from, Vector2 to | Returns the unsigned angle in degrees between from and to.
float | Distance | Vector2& a, Vector2& b | Returns the distance between a and b.
