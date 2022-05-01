#pragma once

#include "Test.h"

namespace test
{
  class TestClearColor : public Test
  {
  public:
    TestClearColor(/* args */);
    ~TestClearColor();

    void OnUpdate(float deltatime) override;
    void OnRender() override;
    void OnImGuiRender() override;

  private:
    float m_ClearColor[4];
  };

} // namespace test
