create user emcs identified by 'emcs';
create database emcsdb CHARACTER SET = utf8 COLLATE utf8_bin;
grant all privileges on emcsdb.* to 'emcs'@'localhost';
flush privileges;
