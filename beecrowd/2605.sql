SELECT products.name AS product_name, providers.name AS provider_name
FROM products
JOIN providers ON products.id_providers = providers.id
JOIN categories ON products.id_categories = categories.id
WHERE categories.id = 6;
