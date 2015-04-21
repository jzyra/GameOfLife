#include "Config.hpp"

Config::Config(string filename) {
	_size = _XNb = _YNb = 0;
	_width = 800;
	_height = 600;
	_YNb = _XNb = 200;
	_title = "Game of life";
	_cellulars = new cellular_t[_size];
	loadJson(filename);
	parseJson();
	checkError();
}

Config::~Config() {
	delete _cellulars;
}

void Config::checkError() {
	if (!(_XNb <= _width)) {
		cerr << "[-] Error, number of cellulars in x (" << _XNb << ") can't be > at : " << _width << endl; 
		exit(1);
	}
	if (!(_YNb <= _height)) {
		cerr << "[-] Error, number of cellulars in y (" << _YNb << ") can't be > at : " << _height << endl; 
		exit(1);
	}
	for (int i=0; i<_size; ++i) {
		if (!(_cellulars[i].x < _XNb)) {
			cerr << "[-] Error, cellular's position in x must be < at " << _XNb << endl;
			exit(1);
		}
		if (_cellulars[i].x < 0) {
			cerr << "[-] Error, cellular's position in x must be > at -1 " << endl;
			exit(1);
		}
		if (!(_cellulars[i].y < _YNb)) {
			cerr << "[-] Error, cellular's position in y must be < at " << _YNb << endl;
			exit(1);
		}
		if (_cellulars[i].y < 0) {
			cerr << "[-] Error, cellular's position in y must be > at -1 " << endl;
			exit(1);
		}
	}
	if (_height < 1) {
		cerr << "[-] Error, Window's height must be > at 0. " << endl;
		exit(1);
	}
	if (_width < 1) {
		cerr << "[-] Error, Window's width must be > at 0. " << endl;
		exit(1);
	}
}

void Config::parseJson() {
	enum json_type type;
	json_object_object_foreach(_json, key, val) {
		//Get value's type.
		type = json_object_get_type(val);
		//Get configuration file datas.
		if (string(key) == "width") {
			if (type == json_type_int)
				_width = json_object_get_int(val);
		} else if (string(key) == "height") {
				if (type == json_type_int)
					_height = json_object_get_int(val);
		} else if (string(key) == "number_cellulars_x") {
				if (type == json_type_int)
					_XNb = json_object_get_int(val);
		} else if (string(key) == "number_cellulars_y") {
				if (type == json_type_int)
					_YNb = json_object_get_int(val);
		} else if (string(key) == "title") {
				if (type == json_type_string)
					_title = json_object_get_string(val);
		} else if (string(key) == "cellulars") {
			if (type == json_type_array) {
				parseCellularsSection(val);
			}
		}
	}
}

void Config::parseCellularsSection(json_object *node) {
	_size = json_object_array_length(node);
	_cellulars = new cellular_t[_size];
	for (int i=0; i < _size; ++i) {
	enum json_type type = json_object_get_type(json_object_array_get_idx(node, i));
		if (type == json_type_object) {
			int x, y;
			bool dead = false;
			x = y = -1;
			//Foreach cellulars defined in configuration file.
			json_object_object_foreach(json_object_array_get_idx(node, i), key, val) {
				type = json_object_get_type(val);
				if (string(key) == "x") {
					if (type == json_type_int)
						x = json_object_get_int(val);
				} else if (string(key) == "y") {
					if (type == json_type_int)
						y = json_object_get_int(val);
				} else if (string(key) == "dead") {
					if (type == json_type_boolean) {
						dead = json_object_get_boolean(val);
					} else {
						dead = false;
					}
				}
			}
			//Check if x and y is > at -1.
			if (x > -1 && y > -1) {
				cellular_t cellular;
				cellular.x = x;
				cellular.y = y;
				cellular.dead = dead;
				_cellulars[i] = cellular;
			} else {
				cerr << "[-] Error: You must have x and y for cellular." << endl;
				exit(1);
			}
		}
	}
}

void Config::loadJson(string filename) {
	ifstream in(filename.c_str());
	if (in.fail()) {
		cerr << "[-] Error when loading file : " << filename << endl;
		exit(1);
	}
	stringstream buffer;
	buffer << in.rdbuf();
	in.close();
	_json = json_tokener_parse((buffer.str()).c_str());
	if (_json == NULL) {
		cerr << "[-] Error: Invalid JSON." << endl;
		exit(1);
	}
}

int Config::getSize() const {
	return _size;
}

int Config::getWidth() const {
	return _width;
}

int Config::getHeight() const {
	return _height;
}

cellular_t *Config::getCellulars() const {
	return _cellulars;
}

int Config::getYNb() const {
	return _YNb;
}

int Config::getXNb() const {
	return _XNb;
}

string Config::getTitle() const {
	return _title;
}
