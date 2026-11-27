# CS 2600 Banking Simulator

Group 10: Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque

## Build and run

From the repository folder, using GCC:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic src/uiMenu.c src/accounts.c src/input.c src/transactions.c src/file_management.c src/history.c -o bank
```

On Windows PowerShell:

```powershell
.\bank.exe
```

On Linux or macOS:

```sh
./bank
```

If Make is installed, `make` builds the same program.

## Menu

1. Account: create an account, view an account, or return to the main menu.
2. Deposit: select an account and enter a dollar amount such as `25.50`.
3. Withdraw: select an account and enter an amount within its balance.
4. Quit.
5. Transfer: select sending and receiving accounts and enter a dollar amount.
6. Transaction history: select an account to display its recorded transactions.

Account numbers start at 1001. New numbers are above the highest loaded account number.
Accounts are loaded from `accounts.txt` at startup and saved after account creation
or a successful transaction. History is appended to `transactions.txt`.
Both files are created in the folder from which you run the program and are ignored by Git.
Run from the same folder to reuse the same data.

## Files and integration

- `src/AccountManagement.h`: the shared account structure and account function declarations.
- `src/accounts.c`: create, search, and view accounts.
- `src/uiMenu.c`: the single entry point and menu connecting the modules.
- `src/input.c` and `src/input.h`: line input, whole numbers, and exact dollar-to-cent conversion.
- `src/transactions.c` and `src/transactions.h`: deposits, withdrawals, and transfers, with history recording.
- `src/file_management.c` and `src/file_management.h`: account saving and loading.
- `src/history.c` and `src/history.h`: transaction recording and display.

The original root-level `Account Management.c` remains a standalone prototype.
Do not include it when compiling the combined program, since it has its own `main()`.
Use the build command above instead of compiling every C file in the repository.

## Applying this update on Windows

1. Open your existing `Banking Simulator\cs2600-final` repository.
2. If `git status` is clean, run `git switch main`, then `git pull origin main`.
3. Run `git switch -c ricky-integrate-banking-modules`.
4. Extract this update ZIP to a temporary folder. Copy its contents into your
   repository folder, replacing matching files and keeping the `src` folder structure.
   Do not replace your repository with a new folder or copy a `.git` directory.
5. Compile and try the menus with the commands above.
6. Stage only the integration files:

```powershell
git add .gitignore README.md makefile src/AccountManagement.h src/accounts.c src/input.c src/input.h src/transactions.c src/transactions.h src/uiMenu.c
git commit -m "Connect banking menu and account modules"
git push -u origin ricky-integrate-banking-modules
```

Open a pull request for that branch when the team is ready to review and merge.

## Validation

Built using C11 with `-Wall -Wextra -Wpedantic` and no warnings.
Checked create/view, deposits, withdrawals, transfers, both sides of transfer history,
restart persistence, nonsequential account IDs, missing accounts, insufficient funds,
self-transfers, zero and negative amounts, excess decimal places, long/blank input,
end of input, and maximum balance overflow.

This remains a classroom simulator: account saving and transaction history use separate
text files, so updates are not atomic across disk failures. A failed history write emits
a warning after the balance change. It has no authentication or concurrent-user support.
