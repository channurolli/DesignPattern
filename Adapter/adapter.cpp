#include <iostream>
#include <string>

using namespace std;

//interface
class MediaPlayer {
    public:
        virtual void play(string audioType, string fileName) = 0;// pure virtual function
};

//interface
class AdvancedMediaPlayer {	
    public:
        virtual void playVlc(string fileName) = 0; // pure virtual function
        virtual void playMp4(string fileName) = 0;
};

//concrete class which plays Vlc audio format
class VlcPlayer: public AdvancedMediaPlayer {
    public:
        void playVlc(string fileName) {
            cout << "Playing vlc file. Name: " + fileName << endl;		
        }
        void playMp4(string fileName) {
            cout << "Vlc player cannot play mp4." << endl;
        }
};

//concrete class which plays Mp4 audio format
class Mp4Player: public AdvancedMediaPlayer {
    public:
        void playVlc(string fileName) {
            cout << "Mp4 player cannot play vlc." << endl;		
        }
        void playMp4(string fileName) {
            cout << "Playing mp4 file. Name: " + fileName  << endl;
        }
};

//creating the adapter class
 class MediaAdapter :public MediaPlayer
{
	AdvancedMediaPlayer *advancedMusicPlayer;

	public: MediaAdapter(string audioType)
		{
			if(audioType == ("vlc"))
			{
				advancedMusicPlayer =new VlcPlayer();  // creating the VlcPlayer object
			}
			else if (audioType==("mp4"))
			{
				advancedMusicPlayer = new Mp4Player();
			}
		}

	public:
			void play(string audioType, string fileName)
	{
		if(audioType=="vlc")
		{
			advancedMusicPlayer->playVlc(fileName);
		}
		else if (audioType == "mp4")
		{
			advancedMusicPlayer->playMp4(fileName);
		}
	}
};



class AudioPlayer: public MediaPlayer {

    public:
	 MediaAdapter* mediaAdapter;

	 	 //default audioplayer
        	void play(string audioType, string fileName) {
            if(audioType == "mp3"){
                cout << "Playing mp3 file. Name: " + fileName << endl;			
            }

            // mediaAdapter provides will allow other media format to play
            else if(audioType == "vlc" || audioType == "mp4"){
            	mediaAdapter = new MediaAdapter(audioType);
            	mediaAdapter->play(audioType,fileName);
            } else {
                cout << "Invalid media. " + audioType + " format not supported" << endl;
            }
        }   
};

int main() {
      AudioPlayer *audioPlayer = new AudioPlayer();
      audioPlayer->play("mp3", "beyond the horizon.mp3"); // plays mp3 from default player
      audioPlayer->play("mp4", "alone.mp4");// plays mp4 from advanced media player
      audioPlayer->play("vlc", "far far away.vlc");// plays vlc from advanced media player
      audioPlayer->play("avi", "mind me.avi");
}

