# MY_RADAR

## OBJECTIVES:

Create an 2D visualization panel showing a simulation of Air Traffic.

The basic **rules** are:
* aircrafts fly from given places to other ones.
* aircrafts appear on the simulation panel when they take off.
* aircrafts disappear from the simulation panel when they land on.
* aircrafts move in a straight line at given constant speeds.
* aircrafts colliding with another one is destroyed and disappear from the simulation panel.
* control areas allow aircrafts to collide with each other without being destroyed and they can continue
on their way.
* control towers don’t move and have control areas on the map.
* control towers appear on the simulation panel at launch.

## Prerequisites:

Information needed in the script in order to start the simulation

#### Aircrafts:
Described in the followig order.

* Named as 'A'
* Departure coordinates [x, y]
* Arrival coordinates [x, y]
* Aircraft speed
* Aircraft delay

#### Control Towers:
Described in the following order.

* Named as 'T'
* Tower coordinates
* Tower radius

## Compilation:
```
> make re
```

## Usage:

Run the following command.
```
> ./my_radar [FILE]
```
#### Parameters:

**FILE** -> The path to the script file.
#### User interactions:

* **'L'** key -> enable/disable hitboxes and areas
* **'S'** key -> enable/disable sprites
