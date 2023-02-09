/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Weather
*/

#include "Weather.hpp"

/**
 * It sends a request to the given URL and returns the response
 *
 * @param url The URL to send the request to.
 * @param post whether or not the request is a POST request
 *
 * @return The text of the webpage.
 */
static std::string sendRequest(std::string url, bool post)
{
    std::string text = "";
    std::string req = "curl --connect-timeout 1 -s -o data.txt ";
    if (post)
        req += "-location --request POST ";
    req += "-L \'" + url + "\'";
    system(req.c_str());
    std::ifstream file("data.txt");
    std::string line;
    if (file.is_open()) {
        while (getline (file, line)) {
            text += line + "\n";
        }
    }
    file.close();
    remove("data.txt");
    return text;
}

/**
 * It replaces all occurrences of a string with another string
 *
 * @param str The string to search and replace in.
 * @param from The string to be replaced
 * @param to The string to replace the from string with.
 *
 * @return A string with all instances of "from" replaced with "to"
 */
static std::string ReplaceAll(std::string str, std::string from, std::string to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

/**
 * It takes a JSON string and a string to search for, and returns the value of the
 * string in the JSON string
 *
 * @param json_res the json response from the server
 * @param str the string to search for in the json_res
 *
 * @return the value of the key that is passed in.
 */
static std::string findInJson(std::string json_res, std::string str)
{
    std::string res = "";
    std::string tmp = "";

    tmp = json_res.substr(json_res.find(str) + str.length() + 4);
    res = tmp.substr(0, tmp.find("\n") - 2);
    return res;
}

/**
 * It takes a JSON string and a variable name, and returns the value of the
 * variable
 *
 * @param json the json string
 * @param var the variable name in the JSON string
 *
 * @return The value of the variable in the json string.
 */
static std::string getValueFromJson(std::string json, std::string var)
{
    std::string res = "";
    size_t pos = json.find(var);
    if (pos != std::string::npos) {
        pos += var.length() + 2;
        while (json[pos] != ',') {
            res += json[pos];
            pos++;
        }
    }
    return res;
}

/**
 * It converts a double to a string
 *
 * @param x the number to be converted
 *
 * @return A string
 */
static std::string dtos(double x)
{
    std::string str;
    std::stringstream ss;
    ss << x;
    str = ss.str();
    return str;
}

/**
 * It converts an unsigned long to a string
 *
 * @param x The number to convert
 *
 * @return A string
 */
static std::string ULtos(size_t x)
{
    std::string str;
    std::stringstream ss;
    ss << x;
    str = ss.str();
    return str;
}

/**
 * It sends a request to the api.ipify.org website, and returns the response
 *
 * @return The IP address of the machine.
 */
static std::string getIP(void)
{
    std::string res = sendRequest("https://api.ipify.org", false);
    return res.substr(0, res.length() - 1);
}

//=============================================================================
//                                 Weather
//=============================================================================

/**
 * The constructor for the Weather class.
 */
Weather::Weather()
{
    Update();
}

/**
 * The destructor is called when the object is destroyed
 */
Weather::~Weather()
{
}

/**
 * It sends a request to the ipinfo.io API to get the user's location, then sends
 * a request to the weatherapi.com API to get the weather data for that location
 */
void Weather::Update(void)
{
    try {
        std::string res = sendRequest("ipinfo.io/" + getIP() + "?token=851a19f5ebe819", false);
        _city = findInJson(res, "city");
        _country = findInJson(res, "country");
        _latitude = std::stod(findInJson(res, "loc").substr(0, findInJson(res, "loc").find(",")));
        _longitude = std::stod(findInJson(res, "loc").substr(findInJson(res, "loc").find(",") + 1));

        std::string request = "https://api.weatherapi.com/v1/current.json?key=615b7050e9204d269b3130539232801&q=" + _city + "&aqi=no";
        res = sendRequest(request, true);
        res = ReplaceAll(res, ",", ",\n");
        _temperature = std::stod(getValueFromJson(res, "temp_c"));
        _humidity = std::stoi(getValueFromJson(res, "humidity"));
        _wind = std::stoi(getValueFromJson(res, "wind_kph"));
        _cloud = std::stoi(getValueFromJson(res, "cloud"));
        _pressure = std::stoi(getValueFromJson(res, "pressure_mb"));
        _precipitation = std::stoi(getValueFromJson(res, "precip_mm"));
        _feelslike = std::stod(getValueFromJson(res, "feelslike_c"));
    }
    catch (const std::exception &e) {}
}

/**
 * It returns a map of strings to strings, where the first string is the name of
 * the data, and the second string is the value of the data
 *
 * @return A map of strings to strings.
 */
std::map<std::string, std::string> Weather::getData(void)
{
    std::map<std::string, std::string> res;
    res["city"] = _city;
    res["country"] = _country;
    res["latitude"] = dtos(_latitude);
    res["longitude"] = dtos(_longitude);
    res["temperature"] = dtos(_temperature);
    res["feelslike"] = dtos(_feelslike);
    res["humidity"] = ULtos(_humidity);
    res["wind"] = ULtos(_wind);
    res["cloud"] = ULtos(_cloud);
    res["pressure"] = ULtos(_pressure);
    res["precipitation"] = ULtos(_precipitation);
    return res;
}