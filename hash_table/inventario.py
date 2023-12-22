from collections import defaultdict

class Item:

    def __init__(self, stock_amount: int, location: str, supplier_info:str , item_code:int):
        self.__stock_amount = stock_amount
        self.__location = location
        self.__supplier_info = supplier_info
        self.__item_code = item_code
    
    # getters
    def get_stock_amount(self):
        return self.__stock_amount
    
    def get_location(self):
        return self.__location
    
    def get_item_code(self):
        return self.__item_code
    
    def get_supplier_info(self):
        return self.__supplier_info
    
    # setters
    def set_stock_amount(self, new_stock_amount):
        self.__stock_amount = new_stock_amount
    
    def set_location(self, location):
        self.__location = location

    def set_supplier_info(self, supplier_info):
        self.__supplier_info = supplier_info

    # Overload return
    def __str__(self):
        return f'\nStock amount: {self.__stock_amount}\nLocation: {self.__location}\nSupplier: {self.__supplier_info}'

    def __repr__(self):
        return f'\nStock amount: {self.__stock_amount}\nLocation: {self.__location}\nSupplier: {self.__supplier_info}'

class Inventory:
    def __init__(self):
        self.inventory_hash = defaultdict(list)

    #methods
    def add_product_to_inventory(self, product:Item):
        self.inventory_hash[product.get_item_code()].append(product)
    
    def consult_item(self, product: Item):
        print(self.inventory_hash[product.get_item_code()])

    def remove_item(self, product: Item):
        self.inventory_hash.pop(product.get_item_code())

    def update_item(self, product: Item):

        while True:
            option = int(input('\n1 - Update stock amount \n2 - Update location \n3 - Update supplier info\n'))

            if option == 1:
                new_stock_amount = int(input('Enter new stock amount: '))
                product.set_stock_amount(new_stock_amount)
                break

            elif option == 2:
                new_location = input('Enter new location: ')
                product.set_location(new_location)
                break

            elif option == 3:
                new_supplier_info = input('Enter new supplier info: ')
                product.set_supplier_info(new_supplier_info)
                break

            else:
                print('Invalid option. Please try again.')

item = Item(item_code=41, location= 'Jaboatao dos guararapes', supplier_info= 'AI COMICS', stock_amount= 10)
item2 = Item(item_code=41, location= 'Jaboatao', supplier_info= 'AI COMICS', stock_amount= 10)
inventory = Inventory()

inventory.add_product_to_inventory(item)
inventory.add_product_to_inventory(item2)
inventory.consult_item(item)

while True:
    inventory.update_item(item)
    inventory.consult_item(item)

    continue_update = input("\nDo you want to continue updating? (y/n): ")
    if continue_update.lower() != 'y':
        break
