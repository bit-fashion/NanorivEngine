/* ************************************************************************
 *
 * Copyright (C) 2022 Vincent Luo All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ************************************************************************/

/* Creates on 2023/11/21. */
#pragma once

#include <Nanoriv.h>
#include <GLFW/glfw3.h>

class NRIVwindow;

typedef void (* PFN_RIVwindowResizableWindowCallback)(NRIVwindow *pRVWidnow, int width, int height);

class NRIVwindow {
public:
    /* Init and create window. */
    NRIVwindow(int width, int height, const char *title);
    ~NRIVwindow();
    /* Support functions. */
    bool WindowShouldClose();
    void ShowWindowInScreen();

public:
    /* Get/Set member variables. */
    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }
    void SetWidth(int width) { m_Width = width; }
    void SetHeight(int height) { m_Height = height; }
    void SetFourierResizableWindowCallback(PFN_RIVwindowResizableWindowCallback fnFourierResizableWindowCallback) /* Set resizable callback. */
      { m_FnFourierResizableWindowCallback = fnFourierResizableWindowCallback; };
    GLFWwindow *GetWindowHandle() { return m_Window; };

private:
    int m_Width;
    int m_Height;
    GLFWwindow *m_Window;
    PFN_RIVwindowResizableWindowCallback m_FnFourierResizableWindowCallback;
};

static void NRIVPollEvents() {
    glfwPollEvents();
}