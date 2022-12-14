// SPDX-License-Identifier: GPL-3.0

pragma solidity 0.5.15;

contract Woodo {
    // address owner; slot #0
    // address unlockTime; slot #1
    constructor (address owner, uint256 unlockTime) public payable {
        assembly { //from EVM
            sstore(0x00, owner)
            sstore(0x01, unlockTime)
        }
    } 
    
    /**
    *  withdraw function from timestamp
    */

    function () external payable {  //get eth
        assembly {
            switch gt(timestamp, sload(0x01))
            case 0 { revert(0,0) }
            case 1 {
                switch call(gas, sload(0x00), balance(address), 0, 0, 0, 0)
                case 0 { revert(0, 0)}
            }
        }
    }
}
