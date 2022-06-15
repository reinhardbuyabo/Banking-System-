# BANKING SYSTEM USING C++

### The first instance of running this code comply to the following ordering:
1. Create an admin text file.
2. Login under admin.
3. Change admin password.
4. Register users under admin.
5. Initialize customer deposits.
6. The rest is upto you.

### This program uses has the following constraints.

- The initial program run should have an additional admin text file previously created with:
    - [x] An admin username specifically on the first line.
    - [x] An admin password specifically on the second line.
- A user can only have one name.
- The user database records only names and passwords.
- The user database has:
    - [x] User names on odd positions of the text file.
    - [x] User passswords on even positions of the text file.
- The user database does not include:
    - [ ] Users' account balance.

The following code implementations have been used interchangably:

```
while (getline(user, userInfo))
```
and

```
while (admin >> adminInfo)
```

[^1]: Other functionalities are going to be apparent upon running this program. 