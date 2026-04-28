package com.mobicom.exercise2

// Do not modify this file except for the package name

class Post(
    val imageId: Int,
    val datePosted: String,
    val caption: String?,
    val location: String?,
    var liked: Boolean,
    val username: String,
    val userImageId: Int) {
}