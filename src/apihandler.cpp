#include "Arduino.h"
#include "apihandler.h"

void APIHandler::setup() {
    String paths[6] = {
        "/on",
        "/hue",
        "/saturation",
        "/brightness",
        "/name",
        "/save-default"
    };

    for (int i = 0; i < 6; i++) {
        String path = paths[i];
        server.on(path, HTTP_GET, std::bind(&APIHandler::handleRequest, this));
        server.on(path, HTTP_POST, std::bind(&APIHandler::handleRequest, this));
    }

    server.onNotFound(std::bind(&APIHandler::handleNotFound, this));
    server.begin();
}

void APIHandler::loop() {
    server.handleClient();
}

void APIHandler::handleRequest() {
    HTTPMethod method = server.method();

    String uri = server.uri();
    Serial.println("URI: " + uri);
    Serial.println("Method: " + method);

    if (method != HTTP_GET && method != HTTP_POST) {
        sendError(400, "Bad request");
        return;
    }

    if (method == HTTP_GET) {
        handleGETRequest();
    }

    if (method == HTTP_POST) {
        handlePOSTRequest();
    }
}

void APIHandler::handleGETRequest() {
    Path path = parsePath();

    // Return an error if trying to GET SAVE_DEFAULT. All other missing paths
    // will be handled by server.onNotFound()
    if (path == SAVE_DEFAULT) {
        sendError(400, "Bad request");
        return;
    }

    // Declare variable to use within switch, which prevents having to use
    // curly braces on every case statement.
    String value = "";

    switch (path) {
        case ON:
            value = strip.getIsOn() ? "true" : "false";
            break;
        case HUE: {
            value = String(strip.getHue(), DEC);
            break;
        }
        case SATURATION:
            value = String(strip.getSaturation(), DEC);
            break;
        case BRIGHTNESS:
            value = String(strip.getBrightness(), DEC);
            break;
        case NAME:
            value = strip.getName();
            break;
    }

    sendRawValue(value);
}

void APIHandler::handlePOSTRequest() {
    Path path = parsePath();
    String arg = server.arg("v");

    if (arg == "" && path != SAVE_DEFAULT) {
        sendError(422, "Bad parameter");
        return;
    }

    switch (path) {
        case ON:
            strip.setIsOn(arg == "true");
            break;
        case HUE:
            strip.setHue(arg.toInt());
            break;
        case SATURATION:
            strip.setSaturation(arg.toInt());
            break;
        case BRIGHTNESS:
            strip.setBrightness(arg.toInt());
            break;
        case NAME:
            strip.setName(arg);
            break;
        case SAVE_DEFAULT:
            strip.saveDefaultColour();
            break;
    }

    sendSuccess();
}

void APIHandler::handleNotFound() {
    sendError(404, "Resource not found");
}

void APIHandler::sendSuccess() {
    String msg = "{\"status\":\"ok\"}";
    server.send(200, "application/json", msg);
}

void APIHandler::sendError(int code, String description) {
    String msg = "{\"status\":\"error\",\"description\":\"" + description + "\"}";
    server.send(code, "application/json", msg);
}

// Sends a raw JSON value, without quotes. String object values should be
// passed in with escaped quotes.
void APIHandler::sendRawValue(String value) {
    String msg = "{\"status\":\"ok\",\"value\":" + value + "}";
    server.send(200, "application/json", msg);
}

// Convert the string path value to an enum case to make it easier to switch
// on values later on.
Path APIHandler::parsePath() {
    String uri = server.uri();
    Serial.println("URI: " + uri);
    if (uri == "/on") {
        return ON;
    } if (uri == "/hue") {
        return HUE;
    } else if (uri == "/saturation") {
        return SATURATION;
    } else if (uri == "/brightness") {
        return BRIGHTNESS;
    } else if (uri == "/name") {
        return NAME;
    } else if (uri == "/save-default") {
        return SAVE_DEFAULT;
    }
}
