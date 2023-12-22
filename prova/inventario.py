from collections import defaultdict

class Item:
    def __init__(self, id_item, stock_amount, supplier_info, lat, lngt, cep, obs):
        self.__id_item = id_item
        self.__stock_amount = stock_amount
        self.__supplier_info = supplier_info
        self.__lat = lat
        self.__lngt = lngt
        self.__cep = cep
        self.__obs = obs

    # getters
    def get_id_item(self):
        return self.__id_item
    
    def get_stock_amount(self):
        return self.__stock_amount
    
    def get_supplier_info(self):
        return self.__supplier_info
    
    def get_lat(self):
        return self.__lat
    
    def get_lngt(self):
        return self.__lngt
    
    def get_cep(self):
        return self.__cep
    
    def get_obs(self):
        return self.__obs

    # setters
    def set_id_item(self, id_item):
        self.__id_item = id_item
    
    def set_stock_amount(self, stock_amount):
        self.__stock_amount = stock_amount
    
    def set_supplier_info(self, supplier_info):
        self.__supplier_info = supplier_info
    
    def set_lat(self, lat):
        self.__lat = lat
    
    def set_lngt(self, lngt):
        self.__lngt = lngt

    def set_cep(self, cep):
        self.__cep = cep
    
    def set_obs(self, obs):
        self.__obs = obs

    def __str__(self):
        return f'Id: {self.__id_item} \nStock amount: {self.__stock_amount} \nSupplier Info: {self.__supplier_info} \nLocation: {self.__lat}, {self.__lngt} \nCEP: {self.__cep} \n OBS: {self.__obs}\n'
    
    def __repr__(self):
        return f'Id: {self.__id_item} \nStock amount: {self.__stock_amount} \nSupplier Info: {self.__supplier_info} \nLocation: {self.__lat}, {self.__lngt} \nCEP: {self.__cep} \n OBS: {self.__obs}\n'


class Inventory:
    def __init__(self):
        self.inventory_hash = defaultdict(list)

    def add_item_to_inventory(self, item:Item):
        self.inventory_hash[item.get_id_item()].append(item)

    def remove_item_from_inventory(self, item:Item):
        self.inventory_hash.pop(item.get_id_item())
    
    def search_item(self, item:Item):
        print(self.inventory_hash[item.get_id_item()])
     
    
item = Item(id_item= 123, stock_amount= 200, supplier_info= 'ADS Dispatch', lat= '07874', lngt= '4528' , cep= '59808-000', obs= 'delivered at 3:40pm')

inventory = Inventory()

inventory.add_item_to_inventory(item)
inventory.search_item(item)
inventory.remove_item_from_inventory(item)