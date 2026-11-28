# Group 10
# Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
# CS2600 Final Project

# If we decide to move everything out of the src folder, remove src/ from the file paths below
banking: src/uiMenu.c src/accounts.c src/transactions.c src/file_management.c src/history.c src/input.c
	gcc -o banking src/uiMenu.c src/accounts.c src/transactions.c src/file_management.c src/history.c src/input.c