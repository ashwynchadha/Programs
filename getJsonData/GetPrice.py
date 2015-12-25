#! /usr/bin/python 
import json
import urllib

 
url = 'http://shopicruit.myshopify.com/products.json'
jsonURL = urllib.urlopen(url)
productList = json.load(jsonURL)
 
grandTotal = 0
listlength = len(productList['products'])

for x in range (0, listlength):
	if (productList['products'][x]['product_type'] == "Wallet" or productList['products'][x]['product_type'] =="Lamp"):
		numberOfVariants = len(productList['products'][x]['variants'])
		for y in range (0, numberOfVariants):
			grandTotal = grandTotal + float(productList['products'][x]['variants'][y]['price']) 

print grandTotal	
