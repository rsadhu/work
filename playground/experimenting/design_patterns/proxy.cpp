#include <iostream>
#include <string>

using namespace std;

// Step 1: Define the interface or abstract class
class Image
{
public:
    virtual void display() = 0;
};

// Step 2: Create the real object
class RealImage : public Image
{
private:
    string filename;

public:
    RealImage(string filename)
    {
        this->filename = filename;
        loadFromDisk(filename);
    }

    void display()
    {
        cout << "Displaying " << filename << endl;
    }

    void loadFromDisk(string filename)
    {
        cout << "Loading " << filename << " from disk." << endl;
    }
};

// Step 3: Create the proxy class
class ProxyImage : public Image
{
private:
    RealImage *realImage;
    string filename;

public:
    ProxyImage(string filename)
    {
        this->filename = filename;
        this->realImage = nullptr;
    }

    void display()
    {
        if (realImage == nullptr)
        {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

// Step 5: Use the proxy object in place of the real object
int main()
{
    Image *image = new ProxyImage("test_image.jpg");

    // The RealImage object is only loaded when the display() method is called on the proxy object
    image->display();

    return 0;
}
