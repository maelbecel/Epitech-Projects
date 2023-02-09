CREATE DATABASE IF NOT EXISTS `Poodle`;
USE Poodle;

CREATE TABLE IF NOT EXISTS users
(
    id INT(11) NOT NULL AUTO_INCREMENT,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    followers_nb INT(11) NOT NULL DEFAULT '0',
    following_nb INT(11) NOT NULL DEFAULT '0',
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS topics
(
    id INT(11) NOT NULL AUTO_INCREMENT,
    url VARCHAR(255) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS comments
(
    id INT(11) NOT NULL AUTO_INCREMENT,
    url VARCHAR(255) NOT NULL,
    user_id INT(11) NOT NULL,
    content TEXT NOT NULL,
    topic_id INT(11) NOT NULL,
    value INT(11) NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (topic_id) REFERENCES topics(id)
);