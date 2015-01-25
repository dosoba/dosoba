http://dev.mysql.com/doc/refman/5.0/en/select.html
SELECT(검색)
SELECT * FROM Writers;
SELECT Id FROM Writers;
SELECT Name FROM Writers;

http://dev.mysql.com/doc/refman/5.0/en/update.html
UPDATE(갱신)
UPDATE Writers SET Name = 'Kim' WHERE Id = 1;

http://dev.mysql.com/doc/refman/5.0/en/insert.html
INSERT(삽입)
insert into Writers (Name) VALUES ('choi');

http://dev.mysql.com/doc/refman/5.0/en/delete.html
DELETE(삭제)
DELETE FROM addressbook;
