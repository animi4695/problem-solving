Amazon Invests in the sucess of entreprenuers, artisans, and small businesses selling int he amazon store. Some of these small business are book stores.

Amazon maintains a portal, where the booksellers  can update their inventories. An update received from the portal is represented by the array *portalUpdate*, whose values indicated the following:

- if *portalUpdate[i]* is a positive integer (for eg. 7), then copy of the book with book ID *portalUpdate[i]* is added to the inventory
- if *portalUpdate[i]* is a negative integer (for eg. -11), then copy of the book with book ID *portalUpdate[i]* (i.e. book ID 11) is removed from the inventory. It is guaranteed that each such update will only be requested if the inventory currently has atleast one copy of that book ID.
- *portalUpdate[i]* is guaranteed to be non-zero.

Given the list of portal updates, the task is to return the maximum copies of any book in the inventory after each update.

Eg.

Consider the number of updates to be n = 6, the updates to be *portalUpdate* = [6, 6, 2, -6, -2, -6];

ans = [1, 2, 2, 1, 1, 0]

explanation:

- After the 1st update, the inventory contains one copy of book ID 6. Maximum copies = 1, of book ID 6.
- After the 2nd update, the inventory contains two copies of book ID 6. Maximum copies = 2, of book ID 6.
- After the 3rd update, the inventory contains two copies of book ID 6 and one copy of book ID 2. Maximum copies = 2, of book ID 6.
- After the 4th update, the inventory contains one copy of book ID 6 and one copy of book ID 2. Maximum copies = 1, of book ID 6 or book ID 2
- After the fifth update, the inventory contains one copy of book ID 6. Maximum copies = 1, of book ID 6.
- After the last update, the inventory is empty. Maximum copies = 0, no books are present.