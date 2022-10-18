--  consulta SQL que retorne a energia média
-- das músicas que são de Drake.

SELECT AVG(energy) FROM songs
WHERE artist_id = (
    SELECT id FROM artists
    WHERE name = "Drake"
);