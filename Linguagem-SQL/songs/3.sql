-- consulta SQL para listar os nomes das
-- 5 músicas mais longas,
-- em ordem decrescente de duração.

SELECT name FROM songs
ORDER BY duration_ms
DESC LIMIT 5;