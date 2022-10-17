-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND
month = 7 AND
day = 28 AND
street = "Humphrey Street";
-- ===== DESCRIPTION ====================================
-- | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

-- O roubo do pato CS50 ocorreu às 10h15 na padaria da Humphrey Street. As entrevistas foram realizadas hoje com três testemunhas que estavam presentes no momento – cada uma das transcrições de suas entrevistas menciona a padaria.


SELECT transcript FROM interviews
WHERE year = 2021 AND
month = 7 AND
day = 28 AND
transcript LIKE "%baker%";

-- ===== TRANSCRIPT =======================================
-- | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

-- Em algum momento, dez minutos depois do roubo, vi o ladrão entrar em um carro no estacionamento da padaria e ir embora. Se você tiver imagens de segurança do estacionamento da padaria, procure carros que saíram do estacionamento nesse período.
-- Não sei o nome do ladrão, mas era alguém que reconheci. No início desta manhã, antes de chegar à padaria de Emma, ​​eu estava passando pelo caixa eletrônico na Leggett Street e vi o ladrão lá sacando algum dinheiro.
-- Quando o ladrão estava saindo da padaria, eles ligaram para alguém que falou com eles por menos de um minuto. Na ligação, ouvi o ladrão dizer que eles planejavam pegar o primeiro voo de Fiftyville amanhã. O ladrão então pediu à pessoa do outro lado do telefone para comprar a passagem aérea.


-- ======== PRIMEIRA BUSCA - TESTEMUNHA 1 ========================
SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND
month = 7 AND
day = 28 AND
hour = 10 AND
minute >= 15 AND minute <= 25
AND activity = "exit";
-- === SUSPECTS ======
-- Vanessa | Bruce   | Barry   | Luca  | Sofia   | Iman    | Diana   | Kelsey


-- =========== SEGUNDA BUSCA - TESTEMUNHA 2 ===============================
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND
month = 7 AND
day = 28 AND
atm_location = "Leggett Street" AND
transaction_type = "withdraw";
-- === STILL SUSPICIOUS ==================
--  Bruce   | Diana   | Iman    | Luca    |


-- ============= TERCEIRA BUSCA - TESTEMUNHA 3 ============================
-- ============= 1 PARTE ==========
SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
    SELECT id FROM flights
    WHERE year = 2021 AND
    month = 7 AND
    day = 29 AND
    origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
    ORDER BY hour,minute
    LIMIT 1);
-- === STILL SUSPICIOUS =======
--  Bruce   | Luca    |
-- === SUSPECTS  ========
-- Doris  | Sofia  | Edward | Kelsey | Taylor | Kenny

-- ============= 2 PARTE ==========
SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND
month = 7 AND
day = 28 AND
duration < 60;
-- === RESULT :: Bruce


-- ============= BUSCA PARA IDENTIFICAR A CIDADE ============
SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND
origin_airport_id = (
    SELECT id FROM airports WHERE city = "Fiftyville"
)
ORDER BY hour, minute
LIMIT 1);
-- === RESULT :: New York City


-- ============= BUSCA PARA IDENTIFICAR O CÚMPLICE ============
SELECT phone_number FROM people WHERE name = "Bruce";
-- === RESULT :: (367) 555-5533
SELECT name FROM people WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year = 2021 AND
    month = 7 AND
    day = 28 AND
    duration < 60 AND
    caller = "(367) 555-5533"
);
-- === RESULT :: Robin