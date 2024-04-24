import java.util.*;

public class MusicPlayer {
    private String deviceName;
    private ArrayList<Song> songList = new ArrayList<Song>();
    private ArrayList<Playlist> listOfPlayList = new ArrayList<Playlist>();
    private int count = 0;

    public MusicPlayer(String deviceName) {
        this.deviceName = deviceName;
    }

    public boolean createPlaylist(String name) {
        if (count < 5) {
            Playlist playList = new Playlist(name);
            listOfPlayList.add(playList);
            count++;
            return true;
        }
        return false;
    }

    public void addSong(Song song) {
        songList.add(song);
    }

    public void addSong(int songIndex, int playlistIndex) {
        Song song = songList.get(songIndex);
        Playlist playlist = listOfPlayList.get(playlistIndex);
        ArrayList<Song> songList = playlist.getSongList();
        songList.add(song);
    }

    public void playSong(int index) {
        Song song = songList.get(index);
        System.out.println(deviceName + " is now playing " + song.getTitle() + "...");
        System.out.println(" ");
        System.out.println("Song by " + song.getArtist());
        System.out.println("Genre: " + song.getGenre() + " | Play time: " + song.getPlayTime());
        System.out.println("==========");
        System.out.println(song.getLyrics());
        System.out.println(" ");
        System.out.println(" ");
    }

    public void playPlaylist(int index) {
        Playlist playlist = listOfPlayList.get(index);
        ArrayList<Song> songs = playlist.getSongList();

        if (songs != null) {
            System.out.println(deviceName + " is now playing " + playlist.getName() + "...");
            for (int i = 0; i < songs.size(); i++) {
                Song song = (Song) songs.get(i);
                //System.out.println(deviceName + " is now playing " + playlist.getName() + "...");
                System.out.println(" ");
                System.out.println(song.getTitle() + " by " + song.getArtist());
                System.out.println("Genre: " + song.getGenre() + " | Play time: " + song.getPlayTime());
                System.out.println("==========");
                System.out.println(song.getLyrics());
                System.out.println(" ");
                System.out.println(" ");
            }
        } else {
            System.out.println("No songs in the playlist");
        }
    }
}