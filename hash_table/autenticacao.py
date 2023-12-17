from collections import defaultdict
from enum import Enum

class AccessLevel(Enum):
    ADMIN = 'Administrador'
    CLIENT = 'Client'

class User:
    def __init__(self, user_id, username, password, access_level):
        self.__user_id = user_id
        self.__username = username
        self.__password = password
        
        if not isinstance(access_level, AccessLevel):
            raise ValueError('Invalid user!')
        self.__access_level = access_level

    # getters
    def get_username(self):
        return self.__username
    
    def get_password(self):
        return self.__password
    
    def get_user_id(self):
        return self.__user_id
    
    def get_access_level(self):
        return self.__access_level
    
    # setters
    def set_user_id(self, user_id):
        self.__user_id = user_id
    
    def set_username(self, username):
        self.__username = username

    def set_password(self, password):
        self.__password = password
    
    def set_access_level(self, acess_level:AccessLevel):
        self.__access_level = acess_level
    
class System:
    def __init__(self):
        self.system = {}

    def register_user(self, user: User):

            existing_users = {(existing_user.get_username(), existing_user.get_password()) for existing_user in self.system.values()}
            
            if (user.get_username(), user.get_password()) in existing_users:
                print('User already registered')
            
            else:
                self.system[user.get_user_id()] = user
    
    def remove_user(self, user:User):
        self.system.pop(user.get_user_id())

    def authenticate(self):
        print('Authentication\n')
        username = input('Username: ')
        password = input('Password: ')

        for user in self.system.values():

            if user.get_username() == username and user.get_password() == password:

                if user.get_access_level() == AccessLevel.ADMIN:
                    print(f'Welcome {user.get_username()}! You are a administrator.')
                    return
                
                elif user.get_access_level() == AccessLevel.CLIENT:
                    print(f'Welcome {user.get_username()}! You are a client.')
                    return
        
        print('Invalid username or password')
        return

system = System()
user1 = User(1, 'admin', '1234', AccessLevel.ADMIN)
user2 = User(2, 'admin', '1234', AccessLevel.CLIENT)

system.register_user(user1)
system.register_user(user2)

system.authenticate()