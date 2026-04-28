package ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.model

/*  Do not modify any declared variables and methods included in this class.
 *
 * The PlayListMediaItem acts as the model for our problem. A media item contains an ID, title,
 *  media type, and media duration. The ID is represented as an integer, while the other variables
 *  are represented as Strings. The class has three constructors of which you're free to use (or not
 *  use). The primary constructor requires all variables be provided, while the others provide a
 *  default ID (i.e. -1). Please note that all variables are not private, so they can be set outside
 *  of the class.
 *
 *  Please also note that there is no validity checking for mediaDuration. It is assumed the input
 *  is correct. However, for mediaType, please make sure that only "AUDIO" or "VIDEO" are specified.
 *  This value is case insensitive, so values like "audio" or "Video" are also allowed.
 */
class PlayListMediaItem(var mediaId: Int, var title: String, var mediaType: String, var mediaDuration: String) {
    companion object {
        private const val DEFAULT_ID = -1
    }

    constructor(title: String, mediaType: String, mediaDuration: String) : this(DEFAULT_ID, title, mediaType, mediaDuration)
    constructor() : this(DEFAULT_ID, "Blank", "VIDEO", "0:0")

    init {
        if(!mediaType.equals("AUDIO", true) and !mediaType.equals("VIDEO", true)) {
            throw MediaItemInitializationException("Initialization of media item's mediaType must be 'Audio' or 'Video' only. Case is ignored during checking, so case variations of the Strings are allowed.")
        }
    }

    // Custom exception class for when the media type isn't properly provided.
    inner class MediaItemInitializationException(message: String) : Exception(message)
}