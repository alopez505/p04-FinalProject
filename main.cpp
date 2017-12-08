#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"bitmap.h"
#include"bitmapEditor.h"

using namespace std;

void showMenu(void);
void choice(int&);

int main()
{
  int menuChoice;
  string filename;
  bitmapEditor image;
  vector<vector<Pixel> > bmp;
  bool validTxtFile;
  cout << "*******************************************************" << endl;
  cout << "*******************************************************" << endl;
  cout << "" << endl;
  cout << "Hello, welcome to Bitmap photo editor, "
    << "what is the name of the photo you would like to edit?" << endl;
  cout <<"(note: If you have a .txt file with the filename, enter 'file')" << endl;
  cin >> filename;
  if(filename == "file")
  {
    string txtFilename;
    string bmpName;
    cout << "What is the name of the text file that contains the name of the file you would like to load?" << endl;
    cin >> txtFilename;
    ifstream file (txtFilename);
    if(file.is_open() )
    {
      file >> bmpName;
      file.close();
      filename = bmpName;
    }
    else{
      do{
        cout << "Unable to open .txt file, please enter a valid .txt filename." << endl;
        cin >> txtFilename;
        ifstream infile (txtFilename);
        validTxtFile = infile.is_open();
        if(infile.is_open() )
        {
          infile >> bmpName;
          infile.close();
          filename = bmpName;
        }
      }while(validTxtFile == false);
    }
  }
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
  cout << filename << " has been loaded. It is " << bmp[0].size() << " pixels wide and " << bmp.size() << " pixels high." << endl;
  do{
    showMenu();
    choice(menuChoice);
    if(menuChoice == 1)
    {
      bmp = image.oldTimeyPhoto();
      image.fromPixelMatrix(bmp);
      cout << "Done" << endl;
    }
    else if(menuChoice == 2)
    {
      bmp = image.brightness();
      image.fromPixelMatrix(bmp);
      cout << "Done" << endl;
    }
    else if(menuChoice == 3)
    {
      bmp = image.warmth();
      image.fromPixelMatrix(bmp);
      cout << "Done" << endl;
    }
    else if(menuChoice == 4)
    {
      bmp = image.saturation();
      image.fromPixelMatrix(bmp);
      cout << "Done" << endl;
    }
    else
    {
      image.save("editedPhoto.bmp");
    }
  }while(menuChoice < 5);
  cout << "Saved!" << endl;

}

void showMenu(void)
{
  cout << "Options: " << endl;
  cout << "(1)OldTimeyPhoto" << endl;
  cout << "(2)Brightness" << endl;
  cout << "(3)Warmth/Cold" << endl;
  cout << "(4)Saturation" << endl;
  cout << "(5)Save and Quit" << endl;
} 

void choice(int & c)
{
  cin >> c;
}
