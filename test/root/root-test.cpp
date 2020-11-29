#include <gtest/gtest.h>
#include <di/di.hpp>
#include <states/base/state.h>
#include <states/enums/state-id.h>
#include <roots/base/root.h>

using namespace OpenGlExample;
using namespace OpenGlExample::States;
namespace di = boost::di;

static int initializeCalledCount;
static int tickCalledCount;
static int renderCalledCount;
static int renderImGuiCalledCount;
static int disposeCalledCount;

#pragma region mockup classes
template<StateId stateId>
class TestState : public State
{
public:
    TestState() : State(stateId) {}

    void initialize() override
    {
        initializeCalledCount++;
    }

    void tick() override
    {
        tickCalledCount++;
    }

    void render() override
    {
        renderCalledCount++;
    }

    void renderImGui() override
    {
        renderImGuiCalledCount++;
    }

    void dispose() override
    {
        disposeCalledCount++;
    }
};

class TestRoot : public Root<TestState<StateId::TEST>>
{};
#pragma endregion

struct RootTest : public testing::Test
{
    std::unique_ptr<OpenGlExample::IRoot> root;

    void SetUp() override
    {
        auto injector = di::make_injector(
            boost::di::bind<OpenGlExample::IRoot>.to<TestRoot>()
        );

        initializeCalledCount = 0;
        tickCalledCount = 0;
        renderCalledCount = 0;
        renderImGuiCalledCount = 0;
        disposeCalledCount = 0;

        root = injector.create<std::unique_ptr<TestRoot>>();
        root->initialize<TestState<StateId::TEST>>();
    }
};

TEST_F(RootTest, root_createFirstStateTest)
{
    EXPECT_EQ(StateId::TEST, root->getCurrentState()->getId());
}

TEST_F(RootTest, tick_tick)
{
    root->tick();
    EXPECT_EQ(1, tickCalledCount);
}

TEST_F(RootTest, render_render)
{
    root->render();
    EXPECT_EQ(1, renderCalledCount);
}

TEST_F(RootTest, renderImGui_renderImGui)
{
    root->renderImGui();
    EXPECT_EQ(1, renderImGuiCalledCount);
}

TEST_F(RootTest, createNewState_createNewState)
{
    root->createState<TestState<StateId::SECOND_TEST>>();
    EXPECT_EQ(StateId::SECOND_TEST, root->getCurrentState()->getId());
}

TEST_F(RootTest, initialize_initializeNewState)
{
    EXPECT_EQ(1, initializeCalledCount);
}

TEST_F(RootTest, dispose_disposeLastState)
{
    root->createState<TestState<SECOND_TEST>>();
    EXPECT_EQ(1, disposeCalledCount);
}