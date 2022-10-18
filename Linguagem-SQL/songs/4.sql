-- consulta SQL que liste os nomes de qualquer música
-- que tenha dançabilidade, energia e valência
-- maiores que 0,75.

SELECT name FROM songs
WHERE danceability > 0.75
AND energy > 0.75
AND valence > 0.75;