-- Section1
    select id from users where LOWER( name ) LIKE  'ali%' order by id asc;
-- Section2
    select sum(orders.price) from orders LEFT join deliveries on orders.delivery_id = deliveries.id
    where deliveries.requested_at >= '2020-01-01 00:00:00' and deliveries.requested_at < '2021-01-01 00:00:00';
-- Section3
    select driver_id from deliveries LEFT join drivers on 
    deliveries.driver_id = drivers.id LEFT join rates on deliveries.id = rates.delivery_id 
    group by driver_id order by avg(rates.rate) desc, driver_id asc limit 10;
-- Section4
    select id, driver_id from deliveries where 
    TIMESTAMPDIFF(second, deliveries.requested_at, deliveries.delivered_at) >= 3 * 3600 order by id asc;
-- Section5
SELECT
    name, phone
FROM
    (
    SELECT
        name, phone,
        (
            6371 * 2 * ATAN2(SQRT(a),
            SQRT(1 - a))
        ) AS d
    FROM
        (
        SELECT
            name, phone,
            ( 
                SIN(dlat / 2) * SIN(dlat / 2) +
                COS(lat_s) * COS(lat_d) * SIN(dlon / 2) * SIN(dlon / 2)
            ) AS a
        FROM
            (
            SELECT
                users.name,
                users.phone,
                RADIANS(ST_X(src) - ST_X(dest)) AS dlat,
                RADIANS(ST_Y(src) - ST_Y(dest)) AS dlon,
                RADIANS(ST_X(src)) AS lat_s,
                RADIANS(ST_X(dest)) AS lat_d
            FROM
                deliveries left join users on deliveries.user_id = users.id
        ) AS t1
    ) AS t2
) AS t3 where d >= 20 group by name having count(d) >= 5 order by name asc