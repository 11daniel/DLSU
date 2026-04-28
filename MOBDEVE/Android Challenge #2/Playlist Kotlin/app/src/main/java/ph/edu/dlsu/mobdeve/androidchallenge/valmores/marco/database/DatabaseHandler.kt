package ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.database

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

/*  This class is open for modification. Please refer to the "TODO" keywords to know what needs to \
 *  be accomplished.
 *
 *  The DatabaseHandler is a custom SQLiteOpenHelper class, which contains the logic for creating
 *  and upgrading the database.
 */

/*  TODO #1
 *      Supply the inheritance needed to make DatabaseHandler a SQLiteOpenHelper class.
 *      Additionally, make sure to supply the appropriate constructor.
 */
class DatabaseHandler(context: Context) :
    SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    // All constant variables needed for the database; Do not modify
    companion object {
        private const val DATABASE_VERSION = 2
        private const val DATABASE_NAME = "PlaylistDatabase"
        const val MEDIA_TABLE = "media_table"

        const val MEDIA_ID = "id"
        const val MEDIA_TITLE = "media_title"
        const val MEDIA_TYPE = "media_type"
        const val MEDIA_DURATION = "media_duration"
    }

    // Handles creation of the database
    override fun onCreate(db: SQLiteDatabase?) {
        /*  TODO #2
         *      Create the SQL statement needed to create the table. Please note that:
         *          + the primary key is an INTEGER type
         *          + all other fields are of TEXT type
         */
        val CREATE_MEDIA_TABLE = "CREATE TABLE $MEDIA_TABLE (" +
                "$MEDIA_ID INTEGER PRIMARY KEY AUTOINCREMENT," +
                "$MEDIA_TITLE TEXT," +
                "$MEDIA_TYPE TEXT," +
                "$MEDIA_DURATION TEXT)"
        db?.execSQL(CREATE_MEDIA_TABLE)

        /*  TODO #3
         *      Insert five (5) media items into the table upon creation. This serves as the dummy
         *      data needed for the app. These should only be added on creation of the DB.
         *      You can create your own items; however, to make things easier for you, please just
         *      consider inserting the dummy information provided in the Canvas page.
         */

        val mediaItems = listOf(
            MediaItem("Bohemian Rhapsody", "AUDIO", "5:55"),
            MediaItem("Stairway to Heaven", "AUDIO", "8:02"),
            MediaItem("Imagine", "AUDIO", "3:03"),
            MediaItem("The Shawshank Redemption", "VIDEO", "2:22:00"),
            MediaItem("Pulp Fiction", "VIDEO", "2:34:00")
        )

        mediaItems.forEach { item ->
            val values = ContentValues().apply {
                put(MEDIA_TITLE, item.title)
                put(MEDIA_TYPE, item.type)
                put(MEDIA_DURATION, item.duration)
            }
            db?.insert(MEDIA_TABLE, null, values)
        }
    }

    /*  Do not modify this method.
     *
     *  Handles the logic needed when updating the database.
     */
    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        db!!.execSQL("DROP TABLE IF EXISTS $MEDIA_TABLE")
        onCreate(db)
    }

    // Data class to represent a media item
    data class MediaItem(val title: String, val type: String, val duration: String)
}
