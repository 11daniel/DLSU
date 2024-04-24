import java.util.*;

public class Playlist {
	private String name;
	private ArrayList<Song> songList = new ArrayList<Song>();

	public Playlist(String name) {
		this.name = name;
	}

	public void addSong(Song song) {
		songList.add(song);
	}

	public String getName() {
		return this.name;
	}

	public ArrayList<Song> getSongList() {
		return this.songList;
	}
}