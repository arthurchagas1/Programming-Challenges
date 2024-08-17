SELECT 
    categories.name AS category_name, 
    SUM(products.amount) AS total_amount
FROM 
    products
JOIN 
    categories ON products.id_categories = categories.id
GROUP BY 
    categories.name
ORDER BY 
    category_name;
