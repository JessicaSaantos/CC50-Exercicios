-- consulta SQL que liste os nomes das músicas
-- que apresentam outros artistas.

SELECT name FROM songs
WHERE name LIKE "%feat%";