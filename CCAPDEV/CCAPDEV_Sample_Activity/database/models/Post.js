const mongoose = require('mongoose')

const PostSchema = new mongoose.Schema({
    title: String,
    description: String,
    content: String,
    image: String
})

const Post = mongoose.model('PostCollection', PostSchema)

module.exports = Post