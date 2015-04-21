/*!
	* \file Config.cpp
	* \brief Class for parse config file.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <json/json.h>
#include "Cellular.hpp"
using namespace std;

class Config {

	public:
	/*!
		* \brief Config Constructor.
		Config class's constructor.
		* \param Path to configuration file.
	*/
	Config(string filename);
	/*!
		* \brief Config Destructor.
		Config class's destructor.
	*/
	~Config();
	/*!
		* \brief Accessor on number of cellulars.
		* \return number of cellulars.
	*/
	int getSize() const;
	/*!
		* \brief Accessor on cellulars matrice.
		* \return pointer to cellulars matrice.
	*/
	cellular_t *getCellulars() const;
	/*!
		* \brief Accessor on windiw's width.
		* \return Window's width in px.
	*/
	int getWidth() const;
	/*!
		* \brief Accessor on window's height.
		* \return Window's height in px.
	*/
	int getHeight() const;
	/*!
		* \brief Accessor on number of cellulars in y axis.
		* \return number of cellulars in y axis.
	*/
	int getYNb() const;
	/*!
		* \brief Accessor on number of cellulars in x axis.
		* \return number of cellulars in x axis.
	*/
	int getXNb() const;
	/*!
		* \brief Accessor on window's title.
		* \return window's title in string format.
	*/
	string getTitle() const;

	private:
	json_object *_json;
	int _width;
	int _height;
	int _XNb;
	int _YNb;
	int _size;
	cellular_t *_cellulars;
	string _title;
	/*!
		* \brief Load json in structure.
		* \param Path to configuration file.
	*/
	void loadJson(string filename);
	/*!
		* \brief Parse json file configuration and get all datas.
	*/
	void parseJson();
	/*!
		* \brief Get all cellulars positions defined in configuration file.
	*/
	void parseCellularsSection(json_object *node);
	/*!
		* \brief Check if datas in configuration file are valid.
	*/
	void checkError();

};

#endif
