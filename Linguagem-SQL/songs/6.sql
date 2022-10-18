-- consulta SQL que liste os nomes das músicas
-- que são de Post Malone.

SELECT name FROM songs
WHERE artist_id = (
    SELECT id FROM artists
    WHERE name = "Post Malone"
);