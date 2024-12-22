CC = gcc
CFLAGS = -o program
SRC = \
	main.c \
	src/adt/mesinkalimat/linemachine.c \
	src/adt/mesinangka/mesinangka.c \
	src/adt/listuser/listuser.c \
	src/adt/mesinkarakter/mesinkarakter.c \
	utilities.c \
	src/adt/mesinkata/mesinkata.c \
	src/adt/queue/queue.c \
	src/adt/arraydinBarang/arraydinBarang.c \
	src/adt/barang/barang.c \
	src/adt/stack/stack.c \
	src/adt/listlinier/listlinier.c \
	src/adt/map/map.c \
	src/spesifikasi/start/start.c \
	src/spesifikasi/load/load.c \
	src/spesifikasi/login/login.c \
	src/spesifikasi/logout/logout.c \
	src/spesifikasi/register/register.c \
	src/spesifikasi/work/work.c \
	src/spesifikasi/work_challenge/work_challenge.c \
	src/spesifikasi/store_list/store_list.c \
	src/spesifikasi/store_remove/store_remove.c \
	src/spesifikasi/store_request/store_request.c \
	src/spesifikasi/store_supply/store_supply.c \
	src/spesifikasi/help/help.c \
	src/spesifikasi/save/save.c \
	src/spesifikasi/profile/profile.c \
	src/spesifikasi/cart/cart_pay.c \
	src/spesifikasi/cart/cart.c \
	src/spesifikasi/cart/cart_show.c \
	src/spesifikasi/history/history.c \
	src/spesifikasi/wishlist_swap/wishlist_swap.c \
	src/spesifikasi/wishlist_remove/wishlist_remove.c \
	src/spesifikasi/wishlist_remove_i/wishlist_remove_i.c \
	src/spesifikasi/wishlist_clear/wishlist_clear.c

all:
	$(CC) $(CFLAGS) $(SRC) -lm

clean:
	rm -f program
