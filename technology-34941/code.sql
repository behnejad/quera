-- Section1
   SELECT * FROM Customers WHERE CustomerName LIKE 'A%' ORDER BY CustomerName ASC
-- Section2
   DELETE u FROM Customers u JOIN(SELECT Country FROM Customers GROUP BY Country HAVING COUNT(*) < 5) tmp ON u.Country = tmp.Country
-- Section3
   SELECT CustomerName FROM Customers l JOIN (SELECT CustomerID FROM Orders m JOIN(SELECT OrderID FROM OrderDetails c JOIN(SELECT ProductID FROM Products ORDER BY Price ASC LIMIT 5) b ON c.ProductID = b.ProductID) v ON m.OrderID = v.OrderID) nn ON l.CustomerID = nn.CustomerID ORDER BY CustomerName ASC
-- Section4
   SELECT DISTINCT SUM(Quantity) AS Sales FROM (SELECT oo.OrderID AS oid, oo.OrderDate, od.ProductID, od.Quantity FROM orders oo JOIN orderdetails od ON oo.OrderID = od.OrderID) x GROUP BY ProductID, DATE_FORMAT(OrderDate, "%Y-%m-01") ORDER BY Sales DESC LIMIT 10