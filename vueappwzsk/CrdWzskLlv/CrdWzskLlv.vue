<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Low-level access</h1>
		<PnlWzskLlvTermArty
			v-if="statshr.pnltermartyAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermArty"
			:scrJref=statshr.scrJrefTermArty
		/>
		<PnlWzskLlvTermClnxevb
			v-if="statshr.pnltermclnxevbAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermClnxevb"
			:scrJref=statshr.scrJrefTermClnxevb
		/>
		<PnlWzskLlvTermIcicle
			v-if="statshr.pnltermicicleAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermIcicle"
			:scrJref=statshr.scrJrefTermIcicle
		/>
		<PnlWzskLlvTermMcvevp
			v-if="statshr.pnltermmcvevpAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermMcvevp"
			:scrJref=statshr.scrJrefTermMcvevp
		/>
		<PnlWzskLlvTermUvbdvk
			v-if="statshr.pnltermuvbdvkAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermUvbdvk"
			:scrJref=statshr.scrJrefTermUvbdvk
		/>
		<PnlWzskLlvCamera
			v-on:request="handleRequest"
			ref="PnlWzskLlvCamera"
			:scrJref=statshr.scrJrefCamera
		/>
		<PnlWzskLlvTtable
			v-on:request="handleRequest"
			ref="PnlWzskLlvTtable"
			:scrJref=statshr.scrJrefTtable
		/>
		<PnlWzskLlvLaser
			v-on:request="handleRequest"
			ref="PnlWzskLlvLaser"
			:scrJref=statshr.scrJrefLaser
		/>
		<PnlWzskLlvTermPwmonuart
			v-if="statshr.pnltermpwmonuartAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermPwmonuart"
			:scrJref=statshr.scrJrefTermPwmonuart
		/>
		<PnlWzskLlvTermPwmonusb
			v-if="statshr.pnltermpwmonusbAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermPwmonusb"
			:scrJref=statshr.scrJrefTermPwmonusb
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskLlvTermArty from './PnlWzskLlvTermArty';
	import PnlWzskLlvTermClnxevb from './PnlWzskLlvTermClnxevb';
	import PnlWzskLlvTermIcicle from './PnlWzskLlvTermIcicle';
	import PnlWzskLlvTermMcvevp from './PnlWzskLlvTermMcvevp';
	import PnlWzskLlvTermUvbdvk from './PnlWzskLlvTermUvbdvk';
	import PnlWzskLlvCamera from './PnlWzskLlvCamera';
	import PnlWzskLlvTtable from './PnlWzskLlvTtable';
	import PnlWzskLlvLaser from './PnlWzskLlvLaser';
	import PnlWzskLlvTermPwmonuart from './PnlWzskLlvTermPwmonuart';
	import PnlWzskLlvTermPwmonusb from './PnlWzskLlvTermPwmonusb';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskLlv',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskLlvTermArty,
			PnlWzskLlvTermClnxevb,
			PnlWzskLlvTermIcicle,
			PnlWzskLlvTermMcvevp,
			PnlWzskLlvTermUvbdvk,
			PnlWzskLlvCamera,
			PnlWzskLlvTtable,
			PnlWzskLlvLaser,
			PnlWzskLlvTermPwmonuart,
			PnlWzskLlvTermPwmonusb
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskLlv.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzskLlv) this.continf = dpcheng.ContInfWzskLlv;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskLlv) this.statapp = dpcheng.StatAppWzskLlv;
				if (dpcheng.StatShrWzskLlv) this.statshr = dpcheng.StatShrWzskLlv;
				if (dpcheng.TagWzskLlv) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlv);
					this.tag = dpcheng.TagWzskLlv;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefTermArty) this.$refs.PnlWzskLlvTermArty.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermClnxevb) this.$refs.PnlWzskLlvTermClnxevb.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermIcicle) this.$refs.PnlWzskLlvTermIcicle.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermMcvevp) this.$refs.PnlWzskLlvTermMcvevp.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermUvbdvk) this.$refs.PnlWzskLlvTermUvbdvk.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefCamera) this.$refs.PnlWzskLlvCamera.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTtable) this.$refs.PnlWzskLlvTtable.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefLaser) this.$refs.PnlWzskLlvLaser.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermPwmonuart) this.$refs.PnlWzskLlvTermPwmonuart.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermPwmonusb) this.$refs.PnlWzskLlvTermPwmonusb.handleReply(obj);
					else console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskLlvData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefTermArty) {
						this.$refs.PnlWzskLlvTermArty.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermClnxevb) {
						this.$refs.PnlWzskLlvTermClnxevb.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermIcicle) {
						this.$refs.PnlWzskLlvTermIcicle.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermMcvevp) {
						this.$refs.PnlWzskLlvTermMcvevp.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermUvbdvk) {
						this.$refs.PnlWzskLlvTermUvbdvk.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefCamera) {
						this.$refs.PnlWzskLlvCamera.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTtable) {
						this.$refs.PnlWzskLlvTtable.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefLaser) {
						this.$refs.PnlWzskLlvLaser.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermPwmonuart) {
						this.$refs.PnlWzskLlvTermPwmonuart.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermPwmonusb) {
						this.$refs.PnlWzskLlvTermPwmonusb.handleUpdate(obj);
						processed = true;
					}
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
