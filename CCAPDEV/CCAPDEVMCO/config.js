const dotenv = require('dotenv');
dotenv.config();
module.exports = {
    envPort: process.env.PORT,
    dbURL: process.env.MONGODB_CONNECT_URI,
    sessionKey: process.env.SESSION_KEY,
  };
  