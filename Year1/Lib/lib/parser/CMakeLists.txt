SET(SRC html/get_balise_content.c
	    html/get_balise_from_place.c
	    html/get_content_by_id.c
	    html/get_content_by_class.c
	    json/coat.c
	    json/fill_file.c
	    json/get_line_pars.c
	    json/get_value.c
	    json/get_update.c
	    json/int_array_from_json.c
	    json/int_from_json.c
	    json/parser.c
	    json/str_from_json.c
	    json/str_array_from_json.c
	    json/update_file.c )

add_library(parser ${SRC})
install(TARGETS parser DESTINATION lib)