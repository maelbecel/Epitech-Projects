SET(SRC displaybinary.c
		displaychar.c
		displaynbr_dec.c
		displaynbr_hexa_capital.c
		displaynbr_hexa.c
		displaynbr_octal.c
		displaynbr.c
		displaypercent.c
		displaypointer.c
		displaystr_unprintable.c
		displaystr.c
		my_printf.c )

add_library(myprintf ${SRC})
install(TARGETS myprintf DESTINATION lib)