Q1.Supermarket Checkout

A supermarket has many customers entering and exiting at various points. They want to keep track of customers and get notification when a customer leaves the store. There are number of checkout lines, where customers with basket of items queue to pay and exit the store. Individual checkout lines and customers are assigned numerical IDs. As happens in life, sometimes customers want to add more items to their baskets and sometimes they realise that they don’t need certain items they picked up earlier and remove them from the basket. To enforce checkout priorities a few rules have been implemented in the supermarket:

A customer cannot switch the lines before eut once they join a given checkout line.

If a customer increases their items to purchase, they must go to the back of the same line.

If a customer removes items from their basket, they will keep their position in the line (or leave the store if

they don’t have any more items).

A customer will leave the supermarket as soon as they have no items left to checkout. Note that the lines with smaller IDs are closer to the exit, so if two customers pass the checkout line at the same time, the one closer to the exit would leave the store first.
You will recieve the stream of N instructions. Each instruction can be one of the following actions:

Customer Enter-indicates that a customer joined a checkout fine.

Attributes: Customerid LineNumber and Numitems

•BasketChange indicates that a customer changed number of items in their basket. Attributes: Customerid and NewNumitems

• LineService-indicates that several items have been processed in the line.

Attributes Line Number and NumProcessed items

• LinesService indicates that 1 item has been processed in every line (if there are k lines then in total items

are processed).

Important Notes:

The New Numitems attribute of the BasketChange action is the number of total items

• Line service calls with no queue in the line should be ignored.

Your task is to keep track of customers and notify when a customer leaves the store.

Function Description

It is required to implement a class that provides methods OnCustomer Enter, OnBasketChange, OnlineService and OnLinesService. These method calls correspond to the instructions described above with the method arguments corresponding to the specified attributes. OnCustomer Exit method is implemented for you and should be called to notify that the customer left the store.

Constraints-
0< N. Customerld. LineNumber<212
0< Numitems NewNumitems, NumProcesseditems 10
ALL

It is guaranteed that On BasketChange will only be called for the customers who are still in the store