public class Tweet
{
  private String userHandle, caption;
  private int likes, imageId;
  private int createdAtYear, createdAtMonth, createdAtDay;
/**
* Returns a tweet.
* <p>
*
* @param userHandle an absolute URL giving the base location of the image
* @param caption the location of the image, relative to the url argument
* @param likes the number of likes
* @param imageId the image id of the tweet
* @param createdAtYear the year the tweet was created
* @param createdAtMonth the month the tweet was created
* @param createdAtDay the day the tweet was created
*/
  public Tweet (String userHandle, String caption, int likes, int imageId, int
				createdAtYear, int createdAtMonth, int createdAtDay)
  {
	this.userHandle = userHandle;
	this.caption = caption;
	this.likes = likes;
	this.imageId = imageId;
	this.createdAtYear = createdAtYear;
	this.createdAtMonth = createdAtMonth;
	this.createdAtDay = createdAtDay;
  }
/**
* Returns the user handle of the tweet made.
* <p>
*
* @return userHandle the user handle of the tweet
*/
  public String getUserHandle ()
  {
	return userHandle;
  }
/**
* Returns the caption on the tweet.
* <p>
*
* @return caption the caption made by the user
*/
  public String getCaption ()
  {
	return caption;
  }
/**
* Returns the number of likes of the tweet.
* <p>
*
* @return likes the number of likes
*/
  public int getLikes ()
  {
	return likes;
  }
/**
* Returns an image id that can then be shown on the screen.
* <p>
*
* @return imageId the image id of the tweet
*/
  public int getImageId ()
  {
	return imageId;
  }
/**
* Returns the date of the when the tweet was created.
* <p>
*
* @return createdAtDay the day the tweet was created
* @return createdAtMonth the month tweet was created
* @return createdAtYear the year the tweet was created
*/
  public String getCreatedAt ()
  {
	return createdAtDay + "/" + createdAtMonth + "/" + createdAtYear;
  }
/**
* Returns the number of likes of the tweet.
* <p>
*
* @param newLikes the location of the image, relative to the url argument
*/
  public void setLikes (int newLikes)
  {
	this.likes = newLikes;
  }
}
