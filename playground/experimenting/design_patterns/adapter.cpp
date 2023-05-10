#include <iostream>
#include <string>

using namespace std;

// Step 1: Define the interface or abstract class that the client expects
class MediaPlayer
{
public:
    virtual void play(string audioType, string filename) = 0;
};

// Step 2: Create the concrete classes that implement the interface
class MP3Player : public MediaPlayer
{
public:
    void play(string audioType, string filename)
    {
        if (audioType == "mp3")
        {
            cout << "Playing MP3 file: " << filename << endl;
        }
    }
};

class OggPlayer
{
public:
    void playOgg(string filename)
    {
        cout << "Playing Ogg file: " << filename << endl;
    }
};

// Step 3: Create the adapter class that "adapts" the incompatible interface to the client interface
class OggAdapter : public MediaPlayer
{
private:
    OggPlayer *oggPlayer;

public:
    OggAdapter(OggPlayer *oggPlayer)
    {
        this->oggPlayer = oggPlayer;
    }

    void play(string audioType, string filename)
    {
        if (audioType == "ogg")
        {
            oggPlayer->playOgg(filename);
        }
    }
};

// Step 5: Use the adapter object to "adapt" the incompatible interface to the client interface
int main()
{
    MediaPlayer *mp3Player = new MP3Player();
    mp3Player->play("mp3", "test_song.mp3");

    OggPlayer *oggPlayer = new OggPlayer();
    MediaPlayer *oggAdapter = new OggAdapter(oggPlayer);
    oggAdapter->play("ogg", "test_song.ogg");

    return 0;
}
