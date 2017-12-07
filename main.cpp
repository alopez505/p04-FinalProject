#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"bitmap.h"
#include"bitmapEditor.h"

using namespace std;







int main()
{
  int menuChoice;
  string filename;
  bitmapEditor image;
  vector<vector<Pixel> > bmp;
  cout << "****************************" << endl;
  cout << "****************************" << endl;
  cout << "" << endl;
  cout << "Hello, welcome to Bitmap photo editor, "
    << "what is the name of the photo you would like to edit?" << endl;
  cin >> filename;
  image.open(filename);
  bool validBmp = image.isImage();
  if( validBmp == true)
  {
    bmp = image.toPixelMatrix();
  }
  else{
    do{
      cout << "File provided cannot be read properly as a bitmap image, the file "
        << "must be a 24 bit depth Windows BMP file. Enter a valid name." << endl;
      cin >> filename;
      image.open(filename);
      validBmp = image.isImage();
    } while(validBmp == false);
    bmp = image.toPixelMatrix();
  }
  cout << filename << "has been loaded. It is " << bmp[0].size() << "pixels wide and " << bmp.size() << " pixels high." << endl;
  do{
  cout << "Options: " << endl;
  cout << "(1)OldTimeyPhoto" << endl;
  cout << "(2)Brightness" << endl;
  cout << "(3)Warmth/Cold" << endl;
  cout << "(4)Saturation" << endl;
  cout << "(5)Border" << endl;
  cout << "(6)Quit" << endl;
  cin >> menuChoice;
  if(menuChoice == 1)
  {
    bmp = image.oldTimeyPhoto();
  }
  else if(menuChoice == 2)
  {
    bmp = image.brightness();
  }
  else if(menuChoice == 3)
  {
    bmp = image.warmth();
  }
  else if(menuChoice == 4)
  {
    bmp = image.saturation();
  }
  else if(menuChoice == 5)
  {
    bmp = image.border();
  }
  else
  {
    image.fromPixelMatrix(bmp);
    image.save("editedPhoto.bmp");
  }
  }while(menuChoice < 6);
  
}
