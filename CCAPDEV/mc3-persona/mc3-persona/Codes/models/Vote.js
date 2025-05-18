const { Schema, SchemaTypes, model } = require('mongoose');

// TODO: Editing not needed, but figure out what you can do
/*()
 * Not necessary to edit...
 */
const voteSchema = new Schema({
    q: String,
});

const Vote = model('Vote', voteSchema);

module.exports = Vote;