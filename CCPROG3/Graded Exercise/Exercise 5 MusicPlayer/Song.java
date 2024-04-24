import java.util.*;

public class Song {
	private String title;
	private String artist;
	private String genre;
	private ArrayList<String> lyrics;
	private float playTime;

	public Song(String title, String artist, String genre, ArrayList<String> lyrics) {
		this.title = title;
		this.artist = artist;
		this.genre = genre;
		this.lyrics = lyrics;
	}

	public String getTitle() {
		return this.title;
	}

	public String getArtist() {
		return this.artist;
	}

	public String getGenre() {
		return this.genre;
	}

	public ArrayList<String> getLyrics() {
		return this.lyrics;
	}

	public float getPlayTime() {
		return this.playTime;
	}
}