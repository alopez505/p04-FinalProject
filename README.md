# Requirements

## Input / Output
[main.cpp lines 20-26](/main.cpp)
I used iostream functions (cin, cout) throughout my project to get user input and to output various options.

## Control Flow
[main.cpp lines 76-103](/main.cpp)
I used multiple if, else if, and else control flow options throughout my project, that specific link shows how i used control flow to get choose what function to use depending on the user input of int menuChoice.

## Iteration
[main.cpp lines 76-104](/main.cpp)
[bitmapEditor.cpp lines 25-48](/bitmapEditor.cpp)
I used a do while loop multiple times in my main.cpp file, the example I linked shows how I used a do while loop to continue to show the menu while menuChoice is less than 5.
I used a for loop for every function in my bitmap.cpp file to go through the matrix of pixels and edit each Pixel.

## Data Structure
[bitmapEditor.cpp line 12](/bitmapEditor.cpp)
I created a matrix (vector of vector) of pixels to represent a Bitmap image because Bitmap images are 2 dimensional grids of Pixels containing rgb values.

## Function
[main.cpp lines 108-116](/main.cpp)
[bitmapEditor.cpp lines 10-48] (/bitmapEditor.cpp)
[bitmapEditor.cpp lines 179-183] (/bitmapEditor.cpp)
[bitmapEditor.cpp lines 118-121] (/bitmapEditor.cpp)
I used a void return type function to display the menu in the first link.
I used a non-void return type function in the second link to return a matrix of Pixels.
I used a pass-by-value function to get the sum of the RGB values in the third link.
I used a pass-by-reference function to get the char of choice in the fourth link.

## File IO
[main.cpp lines 27-54](/main.cpp)
I used instream to use a text file as an input to assign filename.

## Class
[bitmapEditor.h lines 1-20](/bitmap.h)
I created a class named bitmapEditor and it inherited all the traits of bitmap and I added extra functions.

