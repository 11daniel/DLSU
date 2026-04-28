package com.mobdeve.lecturematerial_03_recyclerview

/*  This is our simple data class that contains the ID of the image resource and the name of
    the character. We set the variables to have private setters.
* */
class Character(imageId: Int, name: String) {
    var imageId = imageId
        private set

    var name = name
        private set
}