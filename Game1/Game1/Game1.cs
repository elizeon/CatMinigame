using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;

using System;
using System.Collections.Generic;
using HashTableProject;
//using System.Diagnostics;

namespace Game1
{





    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class Game1 : Game
    {


        public static MouseState mouseState;
        public static KeyboardState keyState;

        // Content directories

        /// <summary>
        /// Texture directory
        /// </summary>
        string texDir = "Content/textures/";

        // Utility variables
        Vector2 baseVec = new Vector2(1, 1);


        // Player vars
        //float moveSpeed = 0.1f;

        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        public static Texture2D whiteTex { get; private set; }

        public static Player player {get{ return m_player; } }

        // Screen
        static float m_screenHeight;
        static float m_screenWidth;
        public static float screenHeight { get { return m_screenHeight; } }
        public static float screenWidth { get { return m_screenWidth; } }


        // Objects
        private static Player m_player = new Player("player","player",10);
        
        Scene m_scene1 = new Scene();
        Scene m_scene2 = new Scene();
        Scene m_scene3 = new Scene();
        Scene m_winScene = new Scene();
        Scene m_loseScene = new Scene();

        static GameGrid m_grid;
        Texture2D testSprite;

        // Textures
        Table<string, Texture2D> m_textures;


        int m_currentScene = 0;
        List<Scene> m_scenes = new List<Scene>();
        public static GameGrid gameGrid { get { return m_grid; } }

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }
        
        string[] m_texArray;

        public void EnterScene(int scn)
        {

            switch(scn)
            {

                case 0:
                    Level1Init();
                    
                    break;
                case 1:
                    Level2Init();
                    break;
                case 2:
                    Level3Init();
                    break;
                case 3:
                    LoseSceneInit();
                    break;
                case 4:
                    WinSceneInit();
                    break;

            }

            m_currentScene = scn;

        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {


            Console.WriteLine("Initialising...");

            base.Initialize();

            Render2D.Instance.Init(GraphicsDevice);

            m_screenHeight = GraphicsDevice.Viewport.Bounds.Height;
            m_screenWidth = GraphicsDevice.Viewport.Bounds.Width;
            m_grid = new GameGrid(10, 10, 0.1f);
            
            
            // Load textures.
            // Load textures.
            m_texArray = new string[]
                {
                    "player",
                    "abc",
                    "bush",
                    "whitepixel",
                    "winscreen",
                    "losescreen",
                    "cursor",
                    "quendaspritesheet",
                    "cat_fluffy",
                    "exit",
                    "completearea",
                    "grass"
                };
            m_textures = LoadTextures(m_texArray, texDir);

            // Initialise objects.
            World.player = m_player;
            whiteTex = m_textures.Get(texDir + "whitepixel");


            m_cursorTex = m_textures.Get(texDir + "cursor");

            testSprite = m_textures.Get(texDir + "abc");



            GlobalObjectsInit();

            EnterScene(0);
            

            m_scenes.Add(m_scene1);
            m_scenes.Add(m_scene2);
            m_scenes.Add(m_scene3);
            m_scenes.Add(m_loseScene);
            m_scenes.Add(m_winScene);


            m_textures = LoadTextures(m_texArray, texDir);

            Console.WriteLine("Initialisation complete.");

        }
        int m_levelsPassed = 0;
        int m_totalLevels = 1;

        void PassLevel(GameTime gameTime, GameObject2D thisobj, GameObject2D other)
        {

            Console.WriteLine("You have completed the level!");
            m_levelsPassed += 1;
            if(m_levelsPassed>=m_totalLevels)
            {
                Win(gameTime, thisobj, other);
            }
        }



        void Win(GameTime gameTime, GameObject2D thisobj, GameObject2D other)
        {
            Console.WriteLine("You have won!");
            EnterScene(4);
        }

        void OtherTakesDamageStop(GameTime gameTime, Enemy thisobj, GameObject2D other)
        {

            //Console.WriteLine("Collision event triggered: Player hit enemy.");
            Console.WriteLine("Collision event triggered: Player hit enemy.");
            other.RegisterHit(gameTime, 10);
            thisobj.SetEnemyState(Enemy.EnemyState.patrolling);
            EnterScene(3);
        }

        /*
        void PlayerHides(GameTime gameTime, Player thisobj, GameObject2D other)
        {
            player.hiding = true;
        }
        */


        Table<string,Texture2D> LoadTextures(string[] tex, string dir)
        {
            Table<string, Texture2D> textures = new Table<string, Texture2D>(tex.Length * 10);

            for (int i = 0; i < m_texArray.Length; i++)
            {
                //Console.WriteLine(i);
                string texstr = dir + tex[i];
                try
                {
                    Texture2D t = Content.Load<Texture2D>(texstr);
                    textures.Add(texstr,t );

                }
                catch (Exception e)
                {
                    Console.WriteLine("ERROR. Exception while trying to read texture " + texstr + ": ");
                    ShowException(e);

                    //catch()
                }
               
            }
            return textures;
        }

        void ShowException(Exception e)
        {
            Console.Write(e.Message+"\n");
            Console.WriteLine("Input e to view full exception or enter to continue.");
            string str = Console.ReadLine();
            if (str.ToUpper() == "E")
            {
                Console.WriteLine(e);
            }
            if(str != "")
            {
                Console.ReadLine();

            }

        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }


        Texture2D m_cursorTex; 

        public float deltaTime { get; private set; }
        private float lastGameTime = 0;
        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            
            Input.Update();
            keyState = Input.keyState;
            mouseState = Mouse.GetState();

            if (m_currentScene == 3 || m_currentScene == 4)
            {
                if(keyState.IsKeyDown(Keys.R))
                {
                    Level1Init();
                    Level2Init();
                    Level3Init();
                    m_currentScene = 0;
                }
            }


            if(m_currentScene<m_scenes.Count)
            {

                m_scenes[m_currentScene].Update(gameTime);
                deltaTime = gameTime.ElapsedGameTime.Milliseconds - lastGameTime;
                lastGameTime = gameTime.ElapsedGameTime.Milliseconds;


            }
            else
            {
                Exit();
            }
            if (keyState.IsKeyDown(Keys.Escape))
            {
                Exit();
            }

            base.Update(gameTime);

        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);
            spriteBatch.Begin();

            base.Draw(gameTime);
            

            m_scenes[m_currentScene].Render(spriteBatch);
            Render2D.Instance.DrawSpriteAtLocation(spriteBatch, m_cursorTex, new Vector2(mouseState.Position.X+m_cursorTex.Width/2,mouseState.Position.Y+m_cursorTex.Height/2), 0, new Vector2(0.6f, 0.6f));


            spriteBatch.End();
        }

        HideLoc m_bush1 = new HideLoc("bush1", "hideloc", 0);
        HideLoc m_bush2 = new HideLoc("bush2", "hideloc", 0);
        HideLoc m_bush3 = new HideLoc("bush3", "hideloc", 0);
        HideLoc m_bush4 = new HideLoc("bush4", "hideloc", 0);
        HideLoc m_bush5 = new HideLoc("bush5", "hideloc", 0);
        Enemy m_testEnemy = new Enemy("enemy1", "enemy", 10);
        GameObject2D m_end = new GameObject2D("end", "end");

        AnimatedSprite m_enemyIdle;
        AnimatedSprite m_enemyWalk;

        Texture2D m_quendaSpritesUD;
        AnimatedSprite m_playerRunUp;
        AnimatedSprite m_playerIdle;
        Texture2D m_bush2D;

        AnimatedSprite m_winScreen;
        AnimatedSprite m_loseScreen;
        AnimatedSprite m_endspr;

        AnimatedSprite m_grass;
        GameObject2D m_grassObj;
        void GlobalObjectsInit()
        {

            m_quendaSpritesUD = m_textures.Get(texDir + "quendaspritesheet");
            m_playerRunUp = new AnimatedSprite(m_quendaSpritesUD, 1, 5);
            m_playerIdle = new AnimatedSprite(m_quendaSpritesUD, 1, 5, 4, 5);
            m_bush2D = m_textures.Get(texDir + "bush");
            Texture2D texcat = m_textures.Get(texDir + "cat_fluffy");
            m_enemyWalk = new AnimatedSprite(texcat, 8, 12,48,51);
            m_enemyWalk.FlipVertical(true);
            m_enemyWalk.playSpeed = 0.5f;




            m_player.scale = new Vector2(1f, 1f);

            m_player.AddAnimSprite("runUp", m_playerRunUp);
            m_player.AddAnimSprite("idle", m_playerIdle);
            m_player.SetAnim("idle");
            m_player.defaultAnim = "idle";

            //m_testEnemy.collisions = false;



            m_testEnemy.scale = new Vector2(1f, 1.5f);
            m_testEnemy.AddAnimSprite("walk", m_enemyWalk);
            m_testEnemy.SetAnim("walk");
            m_testEnemy.defaultAnim = "walk";

            m_winScreen = new AnimatedSprite(m_textures.Get(texDir + "winscreen"), 1, 1);
            m_loseScreen = new AnimatedSprite(m_textures.Get(texDir + "losescreen"), 1, 1);
            

            AnimatedSprite bush = new AnimatedSprite(m_bush2D);
            m_bush1.AddAnimSprite("idle", bush);
            m_bush1.scale = new Vector2(0.5f, 0.5f);
            m_bush1.SetAnim("idle");


            m_bush2.AddAnimSprite("idle", bush);
            m_bush2.scale = new Vector2(0.5f, 0.5f);
            m_bush2.SetAnim("idle");

            m_bush3 = new HideLoc("bush3", m_bush1);
            m_bush3.SetAnim("idle");

            m_bush4 = new HideLoc("bush4", m_bush1);
            m_bush4.SetAnim("idle");

            m_bush5 = new HideLoc("bush5", m_bush1);
            m_bush5.SetAnim("idle");

            m_player.AddCollisionTrigger(m_end, PassLevel);
            m_testEnemy.AddCollisionTrigger(m_player, OtherTakesDamageStop);
            m_endspr = new AnimatedSprite(m_textures.Get(texDir + "exit"));

            m_grass = new AnimatedSprite(m_textures.Get(texDir + "grass"));
            m_grassObj = new GameObject2D("grass", "grass");
            m_grassObj.AddAnimSprite("grass", m_grass);
            m_grassObj.SetAnim("grass");
            m_grassObj.SetPos2D(m_grid.GetPoint(0.5f, 0.5f));

            m_grassObj.scale = new Vector2(screenWidth / (m_grass.texture.Width), screenHeight / (m_grass.texture.Height));
        }
        
        
        void Level1Init()
        {
            m_scene1 = new Scene();

            
            m_player.TriggerLife();

            m_scene1.AddObject(m_grassObj);

            m_bush1.SetPos2D(m_grid.GetPoint(0.9f, 0.2f));
            m_bush2.SetPos2D(   m_grid.GetPoint(0.9f, 0.9f));
            m_bush3.SetPos2D(   m_grid.GetPoint(0.4f, 0.7f));
            m_bush4.SetPos2D(   m_grid.GetPoint(0.7f, 0.2f));
            m_bush5.SetPos2D(   m_grid.GetPoint(0.3f, 0.56f));


            m_scene1.AddObject(m_player);
            m_player.SetPos2D( m_grid.GetPoint(0.5f, 0.5f));


            m_testEnemy.SetPos2D(m_grid.GetPoint(0.2f, 0.2f));
            List<Vector2> patrolPath = new List<Vector2>();
            patrolPath.Add(m_grid.GetPoint(0.1f, 0.1f));
            patrolPath.Add(m_grid.GetPoint(0.1f, 0.5f));
            patrolPath.Add(m_grid.GetPoint(0.2f, 0.3f));
            patrolPath.Add(m_grid.GetPoint(0.5f, 0.7f));
            patrolPath.Add(m_grid.GetPoint(0.6f, 0.7f));
            patrolPath.Add(m_grid.GetPoint(0.9f, 0.8f));
            m_testEnemy.patrolPath = patrolPath;
            m_testEnemy.SetEnemyState(Enemy.EnemyState.patrolling);
            m_testEnemy.StartPatrol(0);
            

            m_scene1.AddObject(m_testEnemy);
            
            m_scene1.AddObject(m_bush1);
            m_scene1.AddObject(m_bush2);
            m_scene1.AddObject(m_bush3);
            m_scene1.AddObject(m_bush4);
            m_scene1.AddObject(m_bush5);
            
            m_end.SetPos2D( m_grid.GetPoint(0.99f, 0.5f));
            Vector2 pointa = m_grid.GetPoint(0.9f, 0.01f);
            Vector2 pointb = m_grid.GetPoint(0.99f, 0.99f);
            m_end.SetCustomBoundingBox(new Rectangle((int)pointa.X, (int)pointa.Y, (int)(pointb.X - pointa.X), (int)(pointb.Y - pointa.Y)));
            m_end.AddAnimSprite("default", m_endspr);
            m_end.SetAnim("default");
            m_end.scale = new Vector2(1.5f, 1f);

            m_scene1.AddObject(m_end);
            
            //m_scene1.AddObject(m_go1);

        }

        

        void Level2Init()
        {
            
        }

        void Level3Init()
        {

            

        }


        void LoseSceneInit()
        {
            GameObject2D loseScreen = new GameObject2D("loseScreen","UI");
            loseScreen.AddAnimSprite("default", m_loseScreen);
            loseScreen.SetAnim("default");
            loseScreen.SetPos2D(   m_grid.GetPoint(0.5f, 0.5f));
            m_loseScene.AddObject(loseScreen);
            
        }

        void WinSceneInit()
        {
            GameObject2D winScreen = new GameObject2D("winScreen", "UI");
            winScreen.AddAnimSprite("default", m_winScreen);
            winScreen.SetAnim("default");
            //winScreen.scale = new Vector2(2, 2);
            winScreen.SetPos2D( m_grid.GetPoint(0.5f, 0.5f));
            m_winScene.AddObject(winScreen);
        }

    }
}
