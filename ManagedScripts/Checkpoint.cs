/*!*************************************************************************
****
\file Checkpoint.cs
\author Go Ruo Yan
\par DP email: ruoyan.go@digipen.edu
\par Course: csd3450
\date 13-02-2024
\brief  Script for button logic
****************************************************************************
***/

using ScriptAPI;
using static DoorState;

public class Checkpoint : Script
{
    #region Door States
    [DontSerializeField] private DoorState.State[] DoorsCheckpoint;

    [DontSerializeField] public DoorState DoorStates;
    #endregion

    #region Painting & Inventory
    [DontSerializeField] private List<string> noteObjsInInventoryCheckpoint;
    [DontSerializeField] private List<string> itemObjsInInventoryCheckpoint;
    [DontSerializeField] private List<string> paintingObjsInInventoryCheckpoint;

    [DontSerializeField] private List<string> notesObjsImgCheckpoint;
    [DontSerializeField] private List<string> itemsObjsImgCheckpoint;
    [DontSerializeField] private List<string> paintingsObjsImgCheckpoint;

    [DontSerializeField] private List<bool> paintingActiveCheckpoint;
    [DontSerializeField] private bool toiletBatteryEnabledCheckpoint;

    public GameObject BedroomPainting;
    public GameObject LivingRoomPainting;
    public GameObject DiningRoomPainting1;
    public GameObject DiningRoomPainting2;
    public GameObject GalleryPainting1;
    public GameObject GalleryPainting2;
    public GameObject GalleryPainting3;

    public GameObject ToiletBattery;
    #endregion

    #region Player
    [DontSerializeField] private Vector3 PlayerPositonCheckpoint;
    [DontSerializeField] private Vector3 PlayerRotationCheckpoint;

    public GameObject Player;
    #endregion

    #region Monster
    [DontSerializeField] private Vector3 MonsterPositonCheckpoint;

    public GameObject Monster;
    #endregion

    public override void Awake()
    {
        DoorsCheckpoint = new DoorState.State[14];
        paintingActiveCheckpoint = new List<bool> { true, true, true, true, true, true, true };
    }

    public override void Update()
    {

    }

    public void OverrideCheckpoint()
    {
        // Door
        for (int i = 0; i < DoorsCheckpoint.Length; i++)
        {
            DoorsCheckpoint[i] = DoorStates.Doors[i];
        }

        // Painting & Inventory
        noteObjsInInventoryCheckpoint = InventoryScript.noteObjsInInventory;
        itemObjsInInventoryCheckpoint = InventoryScript.itemObjsInInventory;
        paintingObjsInInventoryCheckpoint = InventoryScript.paintingObjsInInventory;

        notesObjsImgCheckpoint = InventoryScript.notesObjsImg;
        itemsObjsImgCheckpoint = InventoryScript.itemsObjsImg;
        paintingsObjsImgCheckpoint = InventoryScript.paintingsObjsImg;

        paintingActiveCheckpoint[0] = BedroomPainting.GetActive();
        paintingActiveCheckpoint[1] = LivingRoomPainting.GetActive();
        paintingActiveCheckpoint[2] = DiningRoomPainting1.GetActive();
        paintingActiveCheckpoint[3] = DiningRoomPainting2.GetActive();
        paintingActiveCheckpoint[4] = GalleryPainting1.GetActive();
        paintingActiveCheckpoint[5] = GalleryPainting2.GetActive();
        paintingActiveCheckpoint[6] = GalleryPainting3.GetActive();

        toiletBatteryEnabledCheckpoint = ToiletBattery.GetActive();

        // Player
        PlayerPositonCheckpoint = Player.transform.GetPosition();
        PlayerRotationCheckpoint = Player.transform.GetRotation();

        // Monster
        MonsterPositonCheckpoint = Monster.transform.GetPosition();
    }

    public void RevertToCheckpoint()
    {
        for (int i = 0; i < DoorsCheckpoint.Length; i++)
        {
            DoorStates.Doors[i] = DoorsCheckpoint[i];
        }

        // Painting & Inventory
        InventoryScript.noteObjsInInventory = noteObjsInInventoryCheckpoint;
        InventoryScript.itemObjsInInventory = itemObjsInInventoryCheckpoint;
        InventoryScript.paintingObjsInInventory = paintingObjsInInventoryCheckpoint;

        InventoryScript.notesObjsImg = notesObjsImgCheckpoint;
        InventoryScript.itemsObjsImg = itemsObjsImgCheckpoint;
        InventoryScript.paintingsObjsImg = paintingsObjsImgCheckpoint;

        BedroomPainting.SetActive(paintingActiveCheckpoint[0]);
        LivingRoomPainting.SetActive(paintingActiveCheckpoint[1]);
        DiningRoomPainting1.SetActive(paintingActiveCheckpoint[2]);
        DiningRoomPainting2.SetActive(paintingActiveCheckpoint[3]);
        GalleryPainting1.SetActive(paintingActiveCheckpoint[4]);
        GalleryPainting2.SetActive(paintingActiveCheckpoint[5]);
        GalleryPainting3.SetActive(paintingActiveCheckpoint[6]);

        ToiletBattery.SetActive(toiletBatteryEnabledCheckpoint);

        // Player
        Player.transform.SetPosition(PlayerPositonCheckpoint);
        Player.transform.SetRotation(PlayerRotationCheckpoint);

        // Monster
        Monster.transform.SetPosition(MonsterPositonCheckpoint);

        Monster.GetComponent<GhostMovement>().currentEvent = GhostMovement.GhostEvent.Nothing;
        Monster.GetComponent<GhostMovement>().startEvent = false;
    }
}

